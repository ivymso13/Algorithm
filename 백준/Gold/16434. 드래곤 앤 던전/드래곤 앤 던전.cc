#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 1e18
using namespace std;

typedef long long INT;
typedef pair<int, int> PAIR;

int N, t;
INT att, mA, mT;
vector< PAIR > inp;

INT l, r, mid, ans;
INT hit, curAtt, curHp;

int main() {
    scanf("%d %lld", &N, &att);
    for(int i=0;i<N;i++) {
        scanf("%d %lld %lld", &t, &mA, &mT);

        if(t == 1) inp.push_back({-mA, mT});
        else inp.push_back({mA, mT});
    }

    l = 1;
    ans = r = MAX;
    while(l<=r) {
        mid = (l+r)/2;

        curAtt = att;
        curHp = mid;
        for(int i=0;i<N and curHp > 0;i++) {
            if(inp[i].first > 0) {
                curAtt += inp[i].first;
                curHp = min(curHp+inp[i].second, mid);
            }
            else {
                hit = (inp[i].second - 1)/curAtt;

                curHp = max(curHp - hit*(-inp[i].first), (INT)0);
            }
        }

        if(curHp == 0) l = mid+1;
        else {
            ans = min(ans, mid);
            r = mid-1;
        }
    }

    printf("%lld", ans);
}