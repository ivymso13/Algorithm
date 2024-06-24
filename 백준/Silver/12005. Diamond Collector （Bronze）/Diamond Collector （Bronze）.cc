#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, K, t;
vector< int > inp;

int l, r, len;
int tmp, ret;
map<int, int> check;

int main() {
    scanf("%d %d", &N, &K);
    for(int i=1;i<=N;i++) {
        scanf("%d", &t);
        
        check[t]++;
        inp.push_back(t);
    }
    
    sort(inp.begin(), inp.end());
    inp.erase(unique(inp.begin(), inp.end()), inp.end());
    len = (int)inp.size();
    
    l = r = 0;
    while(r < len) {
        if(inp[r] - inp[l] > K) tmp -= check[inp[l++]];
        else tmp += check[inp[r++]];
        
        ret = max(ret, tmp);
    }
    
    printf("%d", ret);
}
