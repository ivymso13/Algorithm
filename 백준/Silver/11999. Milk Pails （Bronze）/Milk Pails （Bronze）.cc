#include <stdio.h>
#include <algorithm>

int X, Y, M;
int tmp, ret;

int main() {
    scanf("%d %d %d", &X, &Y, &M);
    
    for(int i=0;i<=M/X;i++) {
        tmp = (M-X*i)%Y;
        ret = std::max(ret, M-tmp);
    }
    
    printf("%d", ret);
}
