#include <stdio.h>

int T, a, b, ans;

int main() {
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        scanf("%d %d", &a, &b);
        
        ans = 0;
        while(a<b) {
            a *= 2;
            ans++;
        }
        
        printf("%d\n", ans);
    }
}
