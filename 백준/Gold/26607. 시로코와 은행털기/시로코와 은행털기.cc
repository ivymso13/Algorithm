#include <stdio.h>
#include <string.h>
#include <algorithm>
#define KMAX 85
#define XMAX 205
using namespace std;

int N, K, X, a, b;

int ret;
int dp[KMAX][XMAX*KMAX];

int main() {
    scanf("%d %d %d", &N, &K, &X);

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for(int idx=1;idx<=N;idx++) {
        scanf("%d %d", &a, &b);

        for(int i=K-1;i>=0;i--) {
            for(int j=X*N-a;j>=0;j--) {
                if(dp[i][j] >= 0) dp[i+1][j+a] = max(dp[i+1][j+a], dp[i][j] + b);
            }
        }
    }

    for(int j=1;j<=X*N;j++) ret = max(ret, j*dp[K][j]);

    printf("%d", ret);
}

/*
4 3 4
0 4
4 0
3 1
2 2
ans: 36
*/