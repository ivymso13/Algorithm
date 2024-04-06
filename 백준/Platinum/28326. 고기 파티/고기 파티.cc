#include <stdio.h>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#define NMAX 250010
#define INF 987654321
using namespace std;

typedef long long INT;
typedef pair<int, int> PAIR;

struct Tri {
    int s, e, t;
};

int N, M;
int s, e, t;
int point[2];
INT ret[NMAX];
set< int > val;
vector< Tri > inp;
vector< PAIR > bar;

int len, sz;
int segTree[NMAX*2*4];
vector< PAIR > str;

int bSearch(int val, int f) {
    int l, r, mid;

    l = 0; r = len-1;
    while(l<=r) {
        mid = (l+r)/2;

        if(val == str[mid].first) return mid;
        else if(str[mid].first < val) l = mid+1;
        else r = mid-1;
    }

    return f==0 ? l:r;

}

int segSearch(int l, int r) {
    int ret = INF;

    while(l<=r) {
        if(l%2 == 1) ret = min(ret, segTree[l++]);
        if(r%2 == 0) ret = min(ret, segTree[r--]);

        l/=2; r/=2;
    }

    return ret;
}

int main() {
    // 입력
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++) {
        scanf("%d %d %d", &s, &e, &t);
        inp.push_back({s, e, t});
    }
    for(int i=0;i<M;i++) {
        scanf("%d %d", &point[0], &point[1]);
        bar.push_back({point[0], point[1]});

        // 중복 없이 막대기의 위치 저장 >> 값 압축
        for(int j=0;j<2;j++) {
            if(val.find(point[j]) != val.end()) continue;

            val.insert(point[j]);
            str.push_back({point[j], i});
        }
    }

    // 정렬
    sort(str.begin(), str.end());

    // 막대기의 인덱스를 기준으로 세그먼트 트리 만들기
    len = str.size();
    for(sz=1;sz<len;sz<<=1);
    for(int idx=sz*2-1;idx>=1;idx--) {
        if(idx >= sz+len) segTree[idx] = INF;
        else if(idx >= sz) segTree[idx] = str[idx-sz].second;
        else segTree[idx] = min(segTree[idx*2], segTree[idx*2+1]);
    }

    // 고기가 어느 막대기에 꽂히는지 살펴보기(세그먼트 트리 활용)
    // s: 고기의 s좌표보다 크거나 같은 막대기 중 최솟값
    // e: 고기의 e좌표보다 작거나 같은 막대기 중 최댓값
    // t: 고기가 꽂힐 막대기 >> 고기가 2개 막대기에 꽂혔는지 확인하기
    for(int i=0;i<N;i++) {
        s = bSearch(inp[i].s, 0);
        e = bSearch(inp[i].e-1, 1);
        if(s > e) continue;

        t = segSearch(s+sz, e+sz);
        if(inp[i].s <= bar[t].first and bar[t].second < inp[i].e) ret[t] += inp[i].t;
    }

    // 출력
    for(int i=0;i<M;i++) printf("%lld\n", ret[i]);
}