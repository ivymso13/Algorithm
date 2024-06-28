#include <stdio.h>

int N, K, t, cnt, ret;
int check[15][25];

int main() {
    scanf("%d %d", &K, &N);
    for(int i=1;i<=K;i++) {
        for(int j=1;j<=N;j++) {
            scanf("%d", &t);
            check[i][t] = j;
        }
    }
    
    for(int i=1;i<=N;i++) {
        for(int j=i+1;j<=N;j++) {
            cnt = 0;
            for(int k=1;k<=K;k++) {
                if(check[k][i] < check[k][j]) cnt++;
                else cnt--;
            }
            
            if(cnt == K or cnt == -K) ret++;
        }
    }
    
    printf("%d", ret);
}
