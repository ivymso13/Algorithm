#include <stdio.h>
#include <utility>
#include <algorithm>
#define NMAX 100010
using namespace std;
typedef pair<int, int> PAIR;

int T, N, L, K;
PAIR inp[NMAX];

int cntL, idxL, idxR;
PAIR ret[NMAX];

int main() {
    scanf("%d", &T);
    while(T--) {
        // 초깃값
        idxL = idxR = 0;

        // 입력
        scanf("%d %d %d", &N, &L, &K);
        for(int i=0;i<N;i++) {
            scanf("%d %d", &inp[i].first, &inp[i].second);

            if(inp[i].second < 0) idxR++;
        }

        // [0, idxR) : 왼쪽으로 떨어짐 / [idxR, N) : 오른쪽으로 떨어짐
        // inp[i]은 ret[idxL] or ret[idxR]이 떨어지는 시간에 영향을 끼침
        for(int i=0;i<N;i++) {
            if(inp[i].second < 0) ret[idxL++] = {inp[i].first, inp[idxL].second};
            else ret[idxR++] = {L-inp[i].first, inp[idxR].second};
        }

        // K번째 떨어지는 개미 출력
        sort(ret, ret+N);
        printf("%d\n", ret[K-1].second);
    }
}
