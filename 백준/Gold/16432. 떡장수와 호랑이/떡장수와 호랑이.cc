#include <stdio.h>
#include <string.h>
#include <vector>
#define NMAX 1010
using namespace std;

int N, m, t;
vector< int > inp[NMAX];

int ans;
int dp[NMAX][10];
int trace[NMAX][10];

int sv(int idx, int bef) {
    if(dp[idx][bef] >= 0) return dp[idx][bef];
    
    if(idx > N) return dp[idx][bef] = 1;
    else {
        int ret = 0;
        for(int sel:inp[idx]) {
            if(sel == bef) continue;
            
            if(sv(idx+1, sel) == 1) {
                ret = 1;
                trace[idx][bef] = sel;
            }
        }
        
        return dp[idx][bef] = ret;
    }
}

void print(int idx, int bef) {
    if(idx > N) return;
    
    printf("%d\n", trace[idx][bef]);
    print(idx+1, trace[idx][bef]);
}

int main() {
    // input
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d", &m);
        for(int j=1;j<=m;j++) {
            scanf("%d", &t);
            inp[i].push_back(t);
        }
    }
    
    // dp
    memset(dp, -1, sizeof(dp));
    ans = sv(1, 0);
    
    // print
    if(ans == 0) printf("-1");
    else print(1, 0);
}
