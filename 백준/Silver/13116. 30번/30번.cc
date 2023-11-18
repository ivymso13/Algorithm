#include <stdio.h>

int T, a, b;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &a, &b);

        while(a != b) {
            if(a > b) a /= 2;
            else b /= 2;
        }

        printf("%d\n", a*10);
    }
}