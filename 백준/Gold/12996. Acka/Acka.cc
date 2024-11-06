#include <stdio.h>
#include <string.h>
#define NMAX 55

const int MOD = 1e9+7;

int N, A, B, C;
int dp[NMAX][NMAX][NMAX][NMAX];

int sv(int idx, int a, int b, int c) {
    if(dp[idx][a][b][c] >= 0) return dp[idx][a][b][c];
    else if(idx > N) {
        if(a == 0 and b == 0 and c == 0) return dp[idx][a][b][c] = 1;
        else return dp[idx][a][b][c] = 0;
    }
    else {
        int ret, f;
        int tmp[] = {0, 0, 0};
        
        ret = 0;
        for(int i=1;i<(1<<3);i++) {
            f = 1;
            tmp[0] = c; tmp[1] = b; tmp[2] = a;
            
            for(int j=0, t=i;j<3;j++, t/=2) {
                tmp[j] -= t%2;
                if(tmp[j] < 0) f = 0;
            }
            
            if(f) ret = (ret + sv(idx+1, tmp[2], tmp[1], tmp[0]))%MOD;
        }
        
        return dp[idx][a][b][c] = ret;
    }
}

int main() {
    scanf("%d %d %d %d", &N, &A, &B, &C);
    
    memset(dp, -1, sizeof(dp));
    printf("%d", sv(1, A, B, C)%MOD);
}
