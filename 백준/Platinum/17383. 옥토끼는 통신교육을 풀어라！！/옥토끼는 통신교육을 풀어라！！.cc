#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#define SWAP(a,b)(a=a^b, b=a^b, a=a^b)
using namespace std;

typedef long long INT;

int N, t, ll, rr, f;
vector< INT > inp;

INT l, r, mid;
INT a, b;

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d", &t);
        inp.push_back(t);
    }

    sort(inp.begin(), inp.end());

    l = 1; r = 1e9;
    while(l<=r) {
        // mid는 문제를 푸는데 걸리는 틈
        mid = (l+r)/2;

        // 오래 걸리는 문제부터 풀기 >> a
        // 오래 걸리는 문제가 풀리기 전까지 빨리 걸리는 문제 풀기 >> b
        // 값은 항상 mid의 배수로 저장하기
        a = ((inp[N-1] + (mid-1))/mid)*mid;
        b = 0;

        f = 1;
        ll = 0;
        rr = N-2;
        while(ll<=rr and f) {
            if(a-b == mid) {
                SWAP(a, b);

                a += ((inp[rr] + (mid-1))/mid)*mid;
                rr--;
            }
            else {
                if((inp[ll] + (mid-1))/mid > 1) f = 0;
                else {
                    ll++;
                    b += mid;
                }
            }
        }

        if(!f or a-b>mid) l = mid+1;
        else r = mid-1;
    }

    printf("%lld", l);
}
/*
3
1 1 10
ans: 4
*/