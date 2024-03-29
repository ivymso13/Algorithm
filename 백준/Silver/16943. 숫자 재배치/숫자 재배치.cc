#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int a, b;
int cur, ret;
vector< int > num;

int main() {
    scanf("%d %d", &a, &b);

    while(a > 0) {
        num.push_back(a%10);
        a /= 10;
    }

    sort(num.begin(), num.end());
    ret = -1;

    do {
        if(num[0] == 0) continue;

        cur = 0;
        for(int val:num) cur = cur*10 + val;

        if(cur < b) ret = max(ret, cur);
    }while(next_permutation(num.begin(), num.end()));

    printf("%d", ret);

}