#include <stdio.h>

int N, t, f;

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d", &t);
        
        if(t%2 != i%2) f = 1;
    }

    if(f) printf("NO");
    else printf("YES");
}