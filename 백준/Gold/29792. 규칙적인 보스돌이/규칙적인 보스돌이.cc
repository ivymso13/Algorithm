#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define TMAX 900
using namespace std;

typedef long long INT;

int N, M, K;
INT d, p, q;
vector< INT > D, P, Q;

INT cur, curMax, ret;
INT dp[TMAX+1];

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for(int i=1;i<=N;i++) {
        scanf("%lld", &d);
        D.push_back(d);
    }
    for(int i=1;i<=K;i++) {
        scanf("%lld %lld", &p, &q);

        P.push_back(p);
        Q.push_back(q);
    }

    sort(D.rbegin(), D.rend());

    for(int i=0;i<M;i++) {
        curMax = 0;
        memset(dp, 0, sizeof(dp));

        for(int j=0;j<K;j++) {
            cur = (P[j] + D[i]-1) / D[i];
            for(int k=TMAX;k>=cur;k--) {
                dp[k] = max(dp[k], dp[k-cur] + Q[j]);

                curMax = max(curMax, dp[k]);
            }
        }

        ret += curMax;
    }

    printf("%lld", ret);
}