#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, t;
vector< int > inp;

int l, r;
int tmp, ret;

int main() {
    scanf("%d %d", &N, &K);
    for(int i=1;i<=N;i++) {
        scanf("%d", &t);
        inp.push_back(t);
    }
    
    sort(inp.begin(), inp.end());
    
    l = r = 0;
    while(r < N) {
        if(inp[r] - inp[l] > K) l++;
        else {
            ret = max(ret, r-l+1);
            r++;
        }
    }
    
    printf("%d", ret);
}
