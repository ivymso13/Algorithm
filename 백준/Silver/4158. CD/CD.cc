#include <stdio.h>
#define NMAX 1'000'010

int N, M, t, cnt;
int inp[NMAX];

bool bSearch(int k) {
    int l, r, mid;

    l = 1; r = N;
    while(l<=r) {
        mid = (l+r)/2;

        if(inp[mid] == k) return 1;
        else if(inp[mid] < k) l = mid+1;
        else r = mid-1;
    }

    return 0;
}

int main() {
    while(1) {
        scanf("%d %d", &N, &M);
        if(N==0 and M==0) break;

        cnt = 0;

        for(int i=1;i<=N;i++) scanf("%d", &inp[i]);

        for(int i=1;i<=M;i++) {
            scanf("%d", &t);

            cnt += bSearch(t);
        }

        printf("%d\n", cnt);
    }
}