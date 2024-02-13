#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#define NMAX 100010
#define INF 0x7FFFFFFF
using namespace std;

typedef pair<int, int> PAIR;

int N, S;
PAIR inp[NMAX];

int tmp;
int sumT[NMAX], sumF[NMAX], dp[NMAX];

int main() {
    scanf("%d", &N);
    scanf("%d", &S);
    for(int i=1;i<=N;i++) {
        scanf("%d %d", &inp[i].first, &inp[i].second);
        
        sumT[i] = sumT[i-1] + inp[i].first;
        sumF[i] = sumF[i-1] + inp[i].second;
    }
    
//    dp[idx] : (idx ~ N번째) 작업까지 처리할 때의 필요한 최소 비용
//    >> (idx ~ j번째) 작업을 하나의 배치로 처리할 때의 최소 비용 구하기
//    >> dp[j]에 현재 추가되는 시간(S + T(idx) + ... + T(j-1))만큼 더해서 곱해주기
    
//    dp[idx] = min( dp[j] + (S + T(idx) + T(idx+1) + ... + T(j-1))*(F(idx) + F(idx+1) + ... + F(N) )
//            = min( dp[j] + (S + (sumT[j-1] - sumT[idx-1]))*(sumF[N] - sumF[idx-1]) [ idx <= j <= N ]
    
    for(int i=N;i>=1;i--) {
        dp[i] = (S + sumT[N] - sumT[i-1])*(sumF[N] - sumF[i-1]);
        for(int j=i+1;j<=N;j++) {
            dp[i] = min(dp[i], dp[j] + (S + sumT[j-1]-sumT[i-1])*(sumF[N]-sumF[i-1]));
        }
    }
    
    printf("%d", dp[1]);
}
/*
5
1
1 3
3 2
4 3
2 3
1 4
ans: 153
*/
