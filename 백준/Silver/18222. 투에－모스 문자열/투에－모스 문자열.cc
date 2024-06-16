#include <stdio.h>
typedef long long INT;

INT N, val;
int f;

int main() {
    scanf("%lld", &N);

    for(val=1;val<N;val*=2);

    while(val) {
        if(val < N) {
            f = 1-f;
            N -= val;
        }

        val /= 2;
    }

    printf("%d", f);
}