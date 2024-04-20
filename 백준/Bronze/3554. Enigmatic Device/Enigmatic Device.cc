#include <stdio.h>
#define NMAX 50010
#define MOD 2010

int N, M, q, l, r;
int inp[NMAX];

int sum;

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%d", &inp[i]);

    scanf("%d", &M);
    for(int i=1;i<=M;i++) {
        scanf("%d %d %d", &q, &l, &r);

        sum = 0;
        for(int j=l;j<=r;j++) {
            if(q == 1) inp[j] = (inp[j]*inp[j])%MOD;
            else sum += inp[j];
        }

        if(q == 2) printf("%d\n", sum);
    }
}