#include <stdio.h>
#include <utility>
#include <queue>
#include <map>
using namespace std;
typedef long long INT;
typedef pair<int, int> PAIR;

INT L, N, K, t;

INT idx, val;
queue< INT > q;
map<INT, int> check;

int main() {
    scanf("%lld %lld %lld", &L, &N, &K);
    for(int i=1;i<=N;i++) {
        scanf("%lld", &t);

        check[t] = 1;
        q.push(t);
    }

    while(K--) {
        idx = q.front();
        val = check[idx];
        q.pop();

        printf("%lld\n", val-1);

        for(int d=-1;d<=1;d+=2) {
            if(idx+d < 0 or idx+d > L or check[idx+d]) continue;

            check[idx+d] = val+1;
            q.push(idx+d);
        }
    }
}