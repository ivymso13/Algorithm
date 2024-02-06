#include <stdio.h>
#include <vector>
#include <algorithm>
#define NMAX 100010
#define INF 1e16
typedef long long INT;
using namespace std;

int N, M, K;
INT t;
vector< INT > inp;

INT ret;
INT dp[NMAX][4];

INT getMin() {
    INT ret;
    
    ret = min(inp[K-1]*2, (M-inp[0])*2);
    for(int i=0;i+1<inp.size();i++) ret = min(ret, inp[i]*2 + (M - inp[i+1])*2);

    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    M++;
    
    dp[0][2] = dp[0][3] = INF;
    for(int idx=1;idx<=N;idx++) {
        inp.clear();
        
        scanf("%d", &K);
        for(int j=1;j<=K;j++) {
            scanf("%lld", &t);
            inp.push_back(t);
        }
        
        if(K == 0) {
            for(int j=0;j<4;j++) dp[idx][j] = dp[idx-1][j] + 2;
        }
        
        else {
            // dp[idx][d]: idx번째 층에서 d번 방법으로 올라가고 내려갈 때의 최소 비용
            // 00: 왼쪽 & 왼쪽 / 01: 왼쪽 & 오른쪽 / 10: 오른쪽 & 왼쪽 / 11: 오른쪽 & 오른쪽
            
            // !!! 편의상 M의 값(한 층의 교실 수)을 1 증가시킴 !!!
            dp[idx][0] = min( min(dp[idx-1][0]+inp[K-1]*2, dp[idx-1][1]+M), min(dp[idx-1][2]+M, dp[idx-1][3]+M*2) ) + 2;
            dp[idx][1] = min( min(dp[idx-1][0]+M, dp[idx-1][1]+getMin()), min(dp[idx-1][2]+M*2, dp[idx-1][3]+M) ) + 2;
            dp[idx][2] = min( min(dp[idx-1][0]+M, dp[idx-1][1]+M*2), min(dp[idx-1][2]+getMin(), dp[idx-1][3]+M) ) + 2;
            dp[idx][3] = min( min(dp[idx-1][0]+M*2, dp[idx-1][1]+M), min(dp[idx-1][2]+M, dp[idx-1][3]+(M-inp[0])*2) ) + 2;
            
        }
    }
    
    ret = min( min(dp[N-1][0]+(M-1)*2, dp[N-1][1]+M), min(dp[N-1][2]+M, dp[N-1][3]+(M-1)*2) );
    printf("%lld", ret);
    
}
/*
4 10
1 1
1 10
2 4 6
10 1 2 3 4 5 6 7 8 9 10
ans: 33
 
10 4
2 1 3
2 1 3
2 1 3
2 1 4
0
0
0
0
0
4 1 2 3 4
ans: 38

4 5
2 3 4
1 1
1 1
5 1 2 3 4 5
ans: 22
*/
