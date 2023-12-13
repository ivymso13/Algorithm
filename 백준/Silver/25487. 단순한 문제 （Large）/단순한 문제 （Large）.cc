#include <stdio.h>
#include <algorithm>

int T;
int a, b, c;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &a, &b, &c);
        
        printf("%d\n", std::min(std::min(a, b), c));
    }
}
