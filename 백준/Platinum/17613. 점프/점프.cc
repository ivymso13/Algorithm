#include <stdio.h>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int T, x, y;

int tmp, f=1;
vector< int > jump;
map< pair<int, int>, int > check;

// val보다 작거나 같은 값 반환
int bSearch(int val) {
    int l, r, mid;

    l = 0;
    r = (int)jump.size()-1;
    while(l<=r) {
        mid = (l+r)/2;

        if(jump[mid] == val) return mid;
        else if(jump[mid] < val) l = mid+1;
        else r = mid-1;
    }

    return r;
}

int sv(int x, int y) {
    if(y <= 2) return y;
    else if(check[{x, y}]) return check[{x, y}];

    int idx;
    idx = bSearch(y);

    // jump[] = {0, 1, 3, 7, ... , 2^n-1}
    // jump[idx]을 기준으로 나누기
    if(x < jump[idx]) return check[{x, y}] = max(sv(x, jump[idx]-1), sv(jump[idx], y));
    else return check[{x, y}] = sv(x-jump[idx], y-jump[idx]) + idx;
}

int main() {
    // jump값 초기화
    while(tmp <= 1e9) {
        jump.push_back(tmp);
        tmp += f;
        f *= 2;
    }

    // 입력
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &x, &y);

        // 출력
        printf("%d\n", sv(x, y));
    }
}