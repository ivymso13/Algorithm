#include <stdio.h>
#include <algorithm>
#define NMAX 3010
using namespace std;
typedef long long INT;

int N, M;
INT inp[NMAX][NMAX];

int r;
INT cur;
INT pSum[NMAX][NMAX], ret[NMAX][NMAX];

INT getValue(int x, int y) {
    int x1, y1, x2, y2;
    INT val;

    x1 = max(x-r, 1);
    y1 = max(y-r, 1);

    x2 = min(x+r, N);
    y2 = min(y+r, N);

    val = pSum[x2][y2] - (pSum[x1-1][y2] + pSum[x2][y1-1]) + pSum[x1-1][y1-1];

    return val;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            scanf("%lld", &inp[i][j]);
            inp[i][j] *= -1;
        }
    }

    r = M/2;
    for(int i=1;i+r<=N;i++) {
        for(int j=1;j+r<=N;j++) {
            // 지금까지 누적합 갱신하기
            pSum[i+r][j+r] = pSum[i+r-1][j+r] + pSum[i+r][j+r-1] - pSum[i+r-1][j+r-1];

            // 현재 범위의 값 구하기
            cur = getValue(i, j);

            // 부족한만큼 채워넣기
            ret[i+r][j+r] = inp[i][j] - cur;
            pSum[i+r][j+r] += ret[i+r][j+r];
        }
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            printf("%lld ", ret[i][j]);
        }
        printf("\n");
    }

}