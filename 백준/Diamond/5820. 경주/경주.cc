#include <stdio.h>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#define INF 200010
#define DMAX 1000010
using namespace std;

typedef pair<int, int> PAIR;

int N, K, a, b, t, ans;
vector< PAIR > adj[INF];

int sz[INF], dist[DMAX];
bool visited[INF];

bool check(int idx, int p) { return (!visited[idx] and idx != p); }

int getSz(int idx, int p) {
    sz[idx] = 1;
    for(auto[child, c]:adj[idx]) {
        if(check(child, p)) sz[idx] += getSz(child, idx);
    }
    
    return sz[idx];
}

int getCentroid(int idx, int p, int tot) {
    for(auto[child, c]:adj[idx]) {
        if(check(child, p) and sz[child]*2 > tot) return getCentroid(child, idx, tot);
    }
    
    return idx;
}

int getDist(int idx, int par, int tot, int depth) {
    int ret = INF;
    
    if(tot > K) return ret;
    else if(dist[K-tot] != INF) ret = dist[K-tot] + depth; // dist[K-tot]를 방문한 경우
    
    for(auto[child, c]:adj[idx]) {
        if(!check(child, par)) continue;
        
        ret = min(ret, getDist(child, idx, tot+c, depth+1));
    }
    
    return ret;
}

void update(int idx, int par, int tot, int depth) {
    if(tot > K) return;
    
    // tot까지의 최솟값 갱신
    dist[tot] = min(dist[tot], depth);
    
    for(auto[child, c]:adj[idx]) {
        if(!check(child, par)) continue;
        update(child, idx, tot+c, depth+1);
    }
}

int sv(int idx) {
    int cIdx, ret;
    
    // 센트로이드 탐색
    cIdx = getCentroid(idx, -1, getSz(idx, -1));
    
    // 센트로이드 기준 경로 파악
    for(int i=0;i<=K;i++) dist[i] = INF;
    dist[0] = 0;
    visited[cIdx] = 1;
    
    ret = INF;
    for(auto[child, c]:adj[cIdx]) {
        if(!check(child, cIdx)) continue;
        
        // dist[K]의 최솟값 찾기
        ret = min(ret, getDist(child, cIdx, c, 1));
        
        // cIdx를 기준으로 하는 경로 갱신
        update(child, cIdx, c, 1);
    }
    
    
    // 자식 노드 기준으로 탐색하기
    for(auto[child, c]:adj[cIdx]) {
        if(!visited[child]) ret = min(ret, sv(child));
    }
    
    return ret;
}

int main() {
    scanf("%d %d", &N, &K);
    for(int i=1;i<N;i++) {
        scanf("%d %d %d", &a, &b, &t);
        
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    
    // (1) 현재 트리에서의 센트로이드 찾기
    // (2) 모든 자식 노드부터 센트로이드까지 경로 확인하기
    // (3) 자식 노드로 이동
    ans = sv(0);
    
    if(ans == INF) printf("-1");
    else printf("%d", ans);
}
