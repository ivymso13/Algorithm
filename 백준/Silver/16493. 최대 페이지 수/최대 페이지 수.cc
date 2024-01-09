#include <stdio.h>
#include <algorithm>
#define NMAX 205
using namespace std;

int N, M, d, p, ret;
int dp[NMAX];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1;i<=M;i++) {
        scanf("%d %d", &d, &p);
        for(int j=N-d;j>=0;j--) {
            dp[j+d] = max(dp[j+d], dp[j]+p);
        }
    }

    for(int i=0;i<=N;i++) ret = max(ret, dp[i]);
    printf("%d", ret);
}