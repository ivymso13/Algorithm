#include <stdio.h>
#define NMAX 100010

typedef long long INT;

int N, t;
INT ret;
int inp[NMAX*2], cnt[NMAX];

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d", &inp[i]);
        cnt[inp[i]]++;
    }

    for(int i=1;i<N;i++) {
        t = N-i;

        // inp[i] == 0인 경우, mex(inp[i], inp[j]) = {1, 2}
        // inp[i] == 1인 경우, mex(inp[i], inp[j]) = {0, 2}
        // inp[i] >= 2인 경우, mex(inp[i], inp[j]) = {0, 1}
        if(inp[i] == 0) ret += 2*cnt[1] + 1*(t-cnt[1]);
        else if(inp[i] == 1) ret += 2*cnt[0];
        else ret += 1*cnt[0];

        cnt[inp[i]]--;
    }

    printf("%lld", ret);
}