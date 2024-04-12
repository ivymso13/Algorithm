#include <stdio.h>
#include <algorithm>
#define NMAX 10010
using namespace std;

int N, x, l, c;
int ret, dp[NMAX];

int main() {
    scanf("%d %d", &N, &x);

    dp[0] = 1;
    for(int i=1;i<=N;i++) {
        scanf("%d %d", &l, &c);
        for(int j=x;j>=0;j--) {
            for(int cc=1;cc<=c and j-l*cc>=0;cc++) {
                dp[j] += dp[j-l*cc];
            }
        }
    }

    printf("%d", dp[x]);
}