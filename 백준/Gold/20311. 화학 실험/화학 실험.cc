#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> PAIR;

int N, K, t;
vector< int > ret;

PAIR a, b;
priority_queue< PAIR, vector< PAIR >, less< PAIR > > pq;

int main() {
    scanf("%d %d", &N, &K);
    for(int i=1;i<=K;i++) {
        scanf("%d", &t);

        pq.push({t, i});
    }

    while(!pq.empty()) {
        a = pq.top();
        pq.pop();

        if(pq.empty()) {
            if(a.first > 1) break;
            else ret.push_back(a.second);
        }
        else {
            b = pq.top();
            pq.pop();

            ret.push_back(a.second);
            if(a.first > 1) pq.push({a.first-1, a.second});

            ret.push_back(b.second);
            if(b.first > 1) pq.push({b.first-1, b.second});
        }
    }

    if(ret.size() < N) printf("-1");
    else {
        for(int val:ret) printf("%d ", val);
    }
}