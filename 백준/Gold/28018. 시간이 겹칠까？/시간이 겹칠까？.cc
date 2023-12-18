#include <stdio.h>
#define NMAX 1000010

int N, S, E;
int Q, q;

int check[NMAX];

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d %d", &S, &E);

        check[S]++;
        check[E+1]--;
    }

    for(int i=1;i<NMAX;i++) check[i] += check[i-1];

    scanf("%d", &Q);
    for(int i=1;i<=Q;i++) {
        scanf("%d", &q);

        printf("%d\n", check[q]);
    }
}