#include <stdio.h>
#define NMAX 105

int N, tot, cnt, ret;
int inp[NMAX], pSum[NMAX];

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d", &inp[i]);
        pSum[i] = pSum[i-1] + inp[i];
    }
    
    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j++) {
            cnt = j-i + 1;
            tot = pSum[j] - pSum[i-1];
            
            for(int k=i;k<=j;k++) {
                if(inp[k]*cnt == tot) {
                    ret++;
                    break;
                }
            }
        }
    }
    
    printf("%d", ret);
}
