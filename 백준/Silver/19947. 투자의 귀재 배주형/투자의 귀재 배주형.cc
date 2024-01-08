#include <stdio.h>
#include <algorithm>
#define NMAX 15
using namespace std;

int H, Y;
int dp[NMAX];

int main() {
    scanf("%d %d", &H, &Y);

    dp[0] = H;
    for(int i=1;i<=Y;i++) {
        if(i-1 >= 0) dp[i] = max(dp[i], (int)(dp[i-1]*1.05));
        if(i-3 >= 0) dp[i] = max(dp[i], (int)(dp[i-3]*1.20));
        if(i-5 >= 0) dp[i] = max(dp[i], (int)(dp[i-5]*1.35));
    }

    printf("%d", dp[Y]);
}