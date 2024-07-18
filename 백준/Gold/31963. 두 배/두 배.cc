#include <stdio.h>

int N;
int inp[250010];

long long diff, bef, cur;
long long ret;

long long check[1000010];

int getDiff(int a, int b, int f) {
    int ret = 0;
    
    while(a <= b) {
        if(f and a == b) break;
        
        a *= 2;
        ret++;
    }
    
    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%d", &inp[i]);
    
    for(int i=2;i<=N;i++) {
        if(inp[i-1] < inp[i]) {
            diff = getDiff(inp[i-1], inp[i], 0);
            
            bef = check[inp[i-1]] - diff;
            
            if(bef >= check[inp[i]]) check[inp[i]] = bef+1;
            
        }
        else if(inp[i-1] > inp[i]) {
            diff = getDiff(inp[i], inp[i-1], 1);
            
            cur = check[inp[i]] - diff;
            if(check[inp[i-1]] > cur) check[inp[i]] = check[inp[i-1]] + diff;
        }
        
        ret += check[inp[i]];
        
    }
    
    printf("%lld", ret);
}
