#include <stdio.h>
#include <string.h>
#include <algorithm>
#define NMAX 505
#define INF 987654321
using namespace std;

int N, M;
int inp[NMAX][NMAX], dp[NMAX][NMAX];

int sv(int idx, int bef) {
    if(dp[idx][bef] >= 0) return dp[idx][bef];
    else if(idx > N) return dp[idx][bef] = 0;
    else {
        int ret = INF;
        for(int sel=1;sel<=M;sel++) {
            if(sel == bef) continue;

            ret = min( ret, sv(idx+1, sel) + inp[idx][sel] );
        }

        return dp[idx][bef] = ret;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            scanf("%d", &inp[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));
    printf("%d", sv(1, 0));
}