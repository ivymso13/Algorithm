#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#define NMAX 1000010
using namespace std;
typedef long long INT;
typedef pair<INT, INT> PAIR;

int N;
INT a, b, c;
INT inp[NMAX], pSum[NMAX];

int idx;
INT l, r, mid;
INT dp[NMAX];
vector< int > line;

double getX(PAIR a, PAIR b) { return (double)(b.second-a.second)/(a.first-b.first); }

// f(x) => { -2*a*pSum[j], (a*pSum[j]^2 - b*pSum[j] + dp[j]) } 반환하기
PAIR f(int idx) {
    PAIR ret;
    ret.first = -2*a*pSum[idx];
    ret.second = a*pSum[idx]*pSum[idx] - b*pSum[idx] + dp[idx];

    return ret;
}

// 인덱스 저장하기
void insert(int cur) {
    int sz, p, pp;

    sz = line.size();
    while(sz > 1) {
        p = line[sz-1];
        pp = line[sz-2];

        if(getX(f(p), f(pp)) < getX(f(cur), f(pp))) break;
        line.pop_back();
        sz--;
    }

    line.push_back(cur);
}

int main() {
    scanf("%d", &N);
    scanf("%lld %lld %lld", &a, &b, &c);
    for(int i=1;i<=N;i++) {
        scanf("%lld", &inp[i]);
        pSum[i] = pSum[i-1] + inp[i];
    }

    // x = (pSum[i] - pSum[j])
    // dp[i] = max(dp[i], dp[j] + a*x^2 + b*x + c)
    // dp[i] = max(dp[i], dp[j] + a*pSum[i]^2 - 2*a*pSum[i]*pSum[j] + a*pSum[j]^2 + b*pSum[i] - b*pSum[j] + c)
    //       = max(dp[i], { -2*a*pSum[j]*pSum[i] + (a*pSum[j]^2 - b*pSum[j] + dp[j]) } + (a*pSum[i]^2 + b*pSum[i] + c))
    // line에는 { -2*a*pSum[j], (a*pSum[j]^2 - b*pSum[j] + dp[j]) }의 인덱스(j) 저장하기

    for(int i=1;i<=N;i++) {
        dp[i] = a*pSum[i]*pSum[i] + b*pSum[i] + c;
        l = 0; r = line.size();
        while(r-l>1) {
            mid = (l+r)/2;
            if(getX(f(line[mid]), f(line[mid-1])) <= pSum[i]) l = mid;
            else r = mid;
        }

        if(l < line.size()) idx = line[l];
        else idx = 0;

        dp[i] = max(dp[i], -2*a*pSum[idx]*pSum[i] + (a*pSum[idx]*pSum[idx] - b*pSum[idx] + dp[idx]) + (a*pSum[i]*pSum[i] + b*pSum[i] + c) );

        insert(i);
    }

    printf("%lld", dp[N]);
}