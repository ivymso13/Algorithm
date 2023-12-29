#include <stdio.h>
#include <utility>
#include <algorithm>
#define NMAX 100'010
using namespace std;
typedef pair<int, int> PAIR;

int N, L;
PAIR inp[NMAX];

int cntL, l, r;
PAIR ret[NMAX];

int abs(int k) { return k>0 ? k:-k; }
bool cmp(PAIR a, PAIR b) { return abs(a.first) < abs(b.first); }

int main() {
    // 입력
    scanf("%d %d", &N, &L);
    for(int i=0;i<N;i++) {
        scanf("%d", &inp[i].first);
        inp[i].second = i+1;

        // 오른쪽 방향의 개미 개수 세기
        if(inp[i].first < 0) cntL++;
    }

    // 개미의 위치를 기준으로 정렬
    sort(inp, inp+N, cmp);

    l = r = 0;
    for(int i=0;i<N;i++) {
        // 오른쪽 방향의 개미만큼 왼쪽으로 떨어짐
        // 왼쪽에 떨어지는 개미의 이동 거리 : 가장 가까운 위치에 있는 오른쪽 방향 개미의 이동거리
        // 오른쪽에 떨어지는 개미의 이동 거리 : 가장 가까운 위치에 있는 왼쪽 방향 개미의 이동거리
        if(i < cntL) {
            while(inp[l].first > 0) l++;

            ret[i] = {-inp[l++].first, inp[i].second};
        }
        else {
            while(inp[r].first < 0) r++;
            ret[i] = {L-inp[r++].first, inp[i].second};
        }
        
    }

    // 이동거리 기준으로 정렬
    sort(ret, ret+N);

    // 출력
    printf("%d %d", ret[N-1].second, ret[N-1].first);
}