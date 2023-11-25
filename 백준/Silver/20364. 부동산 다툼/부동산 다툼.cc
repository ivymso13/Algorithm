#include <stdio.h>
#define NMAX (1<<20)

int N, Q, val, d;
int tree[NMAX+1];

int main() {
    scanf("%d %d", &N, &Q);
    for(int i=1;i<=Q;i++) {
        scanf("%d", &val);
        
        d = -1;
        for(int idx=val;idx>0;idx/=2) {
            if(tree[idx]) d = idx;
        }
        
        if(d > 0) printf("%d\n", d);
        else {
            tree[val] = 1;
            printf("0\n");
        }
        
    }
}
