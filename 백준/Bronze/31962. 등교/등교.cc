#include <stdio.h>
#include <algorithm>
using namespace std;

int N, X;
int a, b, ret=-1;

int main() {
    scanf("%d %d", &N, &X);
    for(int i=1;i<=N;i++) {
        scanf("%d %d", &a, &b);
        
        if(a+b<=X) ret = max(ret, a);
    }
    
    
    printf("%d", ret);
}
