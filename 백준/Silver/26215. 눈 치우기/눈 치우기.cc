#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int N, t;
priority_queue< int, vector<int>, less<int> > pq;

int a, b, ret;

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &t);
        pq.push(t);
    }

    while(pq.size() > 1) {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();

        ret += min(a, b);
        if(a == b) continue;
        else pq.push(max(a, b) - min(a, b));
    }

    if(!pq.empty()) ret += pq.top();

    if(ret > 1440) printf("-1");
    else printf("%d", ret);
}