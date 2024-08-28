#include <stdio.h>
#define NMAX 1010
typedef long long INT;

const int MOD = 1e9+7;

int N;
INT ret, f;
INT dp[NMAX][NMAX][50];

int main() {
    scanf("%d", &N);

    dp[0][0][0] = 1;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            for(int k=1;k*(k+1)/2<=N;k++) {
                dp[i][j][k] = dp[i-1][j+1][k]*(j+1);
                if(j-i+1 >= 0) dp[i][j][k] += dp[i-1][j-i+1][k-1]*i;

                dp[i][j][k] %= MOD;
            }
        }
    }

    f = 1;
    for(int k=1;k*(k+1)/2<=N;k++) {
        f = (f*k)%MOD;
        ret = (ret + dp[N][0][k]*f)%MOD;
    }

    printf("%lld", ret);
}