#include <stdio.h>
typedef long long INT;

INT N, X;
INT ham[55], patty[55];

INT sv(INT level, INT layer) {
    if(ham[level] == layer) return patty[level];
    else if(layer == 0) return 0;
    else {
        if(layer <= ham[level-1]+1) return sv(level-1, layer-1);
        else return sv(level-1, ham[level-1]) + sv(level-1, layer-ham[level-1]-2) + 1;
    }
}

int main() {
    scanf("%lld %lld", &N, &X);

    ham[0] = patty[0] = 1;
    for(int i=1;i<=N;i++) {
        ham[i] = ham[i-1]*2 + 3;
        patty[i] = patty[i-1]*2 + 1;
    }

    printf("%lld", sv(N, X));
}