#include <stdio.h>
#include <algorithm>
using namespace std;

int T, N, L, t;
int vmin, vmax;

int main() {
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        // init
        vmin = vmax = 0;

        // input
        scanf("%d %d", &L, &N);
        for(int j=1;j<=N;j++) {
            scanf("%d", &t);

            vmin = max( vmin, min(t, L-t) );
            vmax = max( vmax, max(t, L-t) );
        }

        // print
        printf("%d %d\n", vmin, vmax);
    }
}