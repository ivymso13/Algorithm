#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define NMAX 1010
using namespace std;

typedef long long INT;

struct INP {
    int a, b;
    INT cost;
};

int N, a, b, cnt;
INT t, cst, ret;
int par[NMAX];

struct cmp {
    bool operator()(INP a, INP b) {
        return a.cost > b.cost;
    }
};
priority_queue< INP, vector<INP>, cmp > pq;

int find(int p) {
    if(par[p] == p) return p;
    else return par[p] = find(par[p]);
}

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        par[i] = i;
        for(int j=1;j<=N;j++) {
            scanf("%lld", &t);
            pq.push({i, j, t});
        }
    }

    while(!pq.empty() and cnt<N-1) {
        a = find(pq.top().a);
        b = find(pq.top().b);
        cst = pq.top().cost;
        pq.pop();

        if(par[a] == par[b]) continue;

        par[a] = b;
        ret += cst;
        cnt++;
    }

    printf("%lld", ret);
}