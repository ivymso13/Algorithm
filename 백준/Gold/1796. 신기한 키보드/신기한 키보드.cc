#include <iostream>
#include <vector>
#include <algorithm>
#define NMAX 30
#define INF 987654321
using namespace std;

string inp;
vector< char > tmp;
vector< int > alpha[NMAX];

int sz;
int dp[NMAX][2];

int calc(int idx, int f, int bef) {
    int l, r, ret;
    
    l = alpha[idx][0];
    r = alpha[idx].back();
    
    if(f == 0) {
        if(bef < r) ret = (r - bef) + (r - l);
        else ret = bef - l;
    }
    else {
        if(bef < l) ret = r - bef;
        else ret = (bef - l) + (r - l);
    }
    
    return (ret + (int)alpha[idx].size());
}

int main() {
    cin >> inp;
    
    for(int i=0;inp[i]!='\0';i++) tmp.push_back(inp[i]);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    
    sz = (int)tmp.size();
    for(int i=0;inp[i]!='\0';i++) {
        int idx=0;
        while(tmp[idx] != inp[i]) idx++;
        
        alpha[idx].push_back(i);
    }
    
    dp[0][0] = alpha[0].back() + (alpha[0].back() - alpha[0][0]) + (int)alpha[0].size();
    dp[0][1] = alpha[0].back() + (int)alpha[0].size();
    for(int i=1;i<sz;i++) {
        // dp[i][0]은 이전 위치에서 왼쪽으로 도착하기
        dp[i][0] = min( dp[i-1][0] + calc(i, 0, alpha[i-1][0]), dp[i-1][1] + calc(i, 0, alpha[i-1].back()) );
        dp[i][1] = min( dp[i-1][0] + calc(i, 1, alpha[i-1][0]), dp[i-1][1] + calc(i, 1, alpha[i-1].back()) );
        
    }
    
    printf("%d", min(dp[sz-1][0], dp[sz-1][1]));
    
}
