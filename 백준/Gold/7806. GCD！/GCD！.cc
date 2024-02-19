#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>
#define NMAX 100'010
#define MAX 1'000'000'000
using namespace std;

typedef long long INT;

int N, K;
int check[NMAX];
vector< int > prime;

int idx, tmp, ret;
int cnt[NMAX];
set< int > num;

int main() {
    // init
    prime.push_back(2);
    for(INT i=3;i*i<=MAX;i+=2) {
        if(check[i]) continue;

        prime.push_back(i);
        for(INT j=i;j*j<=MAX;j+=i) check[j] = 1;
    }


    while(scanf("%d %d", &N, &K) != EOF) {
        idx = 0;
        num.clear();
        memset(cnt, 0, sizeof(cnt));

        while(K>1 and idx<prime.size()) {
            if(K%prime[idx] != 0) idx++;
            else {
                num.insert(prime[idx]);
                cnt[prime[idx]]++;

                K /= prime[idx];
                idx = 0;
            }
        }

        if(N >= K) ret = K;
        else ret = 1;

        for(int val:num) {
            tmp = 0;
            
            // n!에서 val의 개수 세기
            for(int j=val;j<=N;j*=val) tmp = tmp + N/j;
            tmp = min(tmp, cnt[val]);

            // GCD 구하기
            for(int j=1;j<=tmp;j++) ret *= val;
        }

        printf("%d\n", ret);

    }

}