#include <stdio.h>
#include <vector>
#include <algorithm>
#define NMAX 100010
using namespace std;
typedef long long INT;

struct Line {
    // ax + b
    // x: 시작하는 x값
    INT a, b;
};

INT N, l, r, mid;
INT x;
INT a[NMAX], b[NMAX], dp[NMAX];

Line cur;
vector< Line > v;

// 교점의 x좌표 구하기
double getX(Line p1, Line p2) { return (double)(p2.b-p1.b)/(p1.a-p2.a); }

void insert(Line line) {
    int sz;
    Line p, pp;
    double bef, cur;
    
    sz = (int)v.size();
    while(sz > 1) {
        p = v[sz-1];
        pp = v[sz-2];
        
        // 교점의 x좌표 구하기
        bef = getX(p, pp);
        cur = getX(line, p);
        
        // 현재 교점의 x좌표가 오른쪽에 있으면 바로 넣기
        if(bef < cur) break;
        
        // 현재 교점의 x좌표가 왼쪽에 있으면 이전 선분 빼기
        v.pop_back();
        sz--;
    }
    
    v.push_back(line);
}

int main() {
    // 입력
    scanf("%lld", &N);
    for(int i=1;i<=N;i++) scanf("%lld", &a[i]);
    for(int i=1;i<=N;i++) scanf("%lld", &b[i]);
    
    // dp[i] = min(dp[i], dp[j] + b[j]*a[i])
    // >> ax + b = b[j]*x + dp[j]
    v.push_back({b[1], 0});
    for(int i=2;i<=N;i++) {
        // x(a[i])를 포함하는 선분 찾기
        // >> 선분 사이의 교점을 기준으로 찾기
        x = a[i];
        l = 0; r = (int)v.size();
        while(r-l>1) {
            mid = (l+r)/2;
            
            if(getX(v[mid], v[mid-1]) <= x) l = mid;
            else r = mid;
        }
        
        // l번째 선분의 값
        dp[i] = v[l].a*x + v[l].b;
        
        // 선분 넣기
        insert({b[i], dp[i]});
    }
    
    // 출력
    printf("%lld", dp[N]);
}
