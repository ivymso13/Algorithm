#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#define INF 1'000'000'000
using namespace std;

int N, K, len, t;
vector< int > inp;
map< int, int > check;

int ret, nxt;
int l, r, tmp, sz;
int f[50010], segTree[50'000*4];

int bSearch(int val) {
    int l, r, mid;
    
    l = 0; r = sz-1;
    while(l<=r) {
        mid = (l+r)/2;
        
        if(inp[mid] <= val) l = mid+1;
        else r = mid-1;
    }
    
    return l;
}

int segSearch(int l, int r) {
    int ret;
    
    ret = 0;
    while(l<=r) {
        if(l%2==1) ret = max(ret, segTree[l++]);
        if(r%2==0) ret = max(ret, segTree[r--]);
        
        l/=2; r/=2;
    }
    
    return ret;
}

int main() {
    scanf("%d %d", &N, &K);
    for(int i=0;i<N;i++) {
        scanf("%d", &t);
        
        inp.push_back(t);
        check[t] += 1;
    }
    
    sort(inp.begin(), inp.end());
    inp.erase(unique(inp.begin(), inp.end()), inp.end());
    
    len = (int)inp.size();
    l = r = 0;
    while(l < len) {
        if(r == len) {
            f[l] = tmp;
            tmp -= check[inp[l++]];
        }
        else {
            if(inp[r] - inp[l] > K) tmp -= check[inp[l++]];
            else tmp += check[inp[r++]];
            
            f[l] = tmp;
        }
    }
    
    for(sz=1;sz<len;sz*=2);
    for(int i=sz*2-1;i>=1;i--) {
        if(i >= sz) segTree[i] = f[i-sz];
        else segTree[i] = max(segTree[i*2], segTree[i*2+1]);
    }
    
    for(int i=0;i<len;i++) {
        nxt = bSearch(inp[i] + K);
        
        ret = max(ret, f[i] + segSearch(nxt+sz, (len-1)+sz));
    }
    
    printf("%d", ret);
    
}
