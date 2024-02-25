#include <stdio.h>
#include <string.h>
#include <algorithm>
#define NMAX 300010
using namespace std;

int N;
int inp[NMAX];

int ret;
int dp[NMAX][1<<3][3];

int sv(int idx, int check, int cur) {
    if(dp[idx][check][cur] >= 0) return dp[idx][check][cur];
    else if(idx > N) return dp[idx][check][cur] = 0;
    else {
        int ret = 0;

        if(inp[idx] == cur) ret = sv(idx+1, check, cur) + 1;
        else {
            ret = sv(idx+1, check, cur);
            if( !(check & (1<<inp[idx])) ) ret = max( ret, sv(idx+1, check|(1<<inp[idx]), inp[idx])+1 );
        }

        return dp[idx][check][cur] = ret;
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%d", &inp[i]);

    memset(dp, -1, sizeof(dp));
    for(int k=0;k<3;k++) ret = max(ret, sv(1, 1<<k, k));

    printf("%d", ret);
}