#include <stdio.h>
#include <string.h>
#include <algorithm>
#define NMAX 21
using namespace std;

int N;
int inp[NMAX][NMAX];

double dp[1<<NMAX];

double sv(int idx, int check) {
    if(dp[check] > 0) return dp[check];
    else if(idx > N) return dp[check] = 1;
    else {
        double ret=0;
        for(int nxt=1;nxt<=N;nxt++) {
            if(check & (1<<nxt)) continue;

            ret = max( ret, sv(idx+1, check|(1<<nxt))*inp[idx][nxt] );
        }

        return dp[check] = ret/100.0;
    }
}

int main() {
    // input
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            scanf("%d", &inp[i][j]);
        }
    }

    // sv
    printf("%lf", sv(1, 0)*100);
}