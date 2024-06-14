#include <stdio.h>

int N, cnt;

int main() {
    scanf("%d", &N);
    for(int i=1;i*i<=N;i++) {
        if(N%i == 0) {
            if(i*i == N) cnt++;
            else cnt += 2;
        }
    }

    printf("%d", cnt);
}