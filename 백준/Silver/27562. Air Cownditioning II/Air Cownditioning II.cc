#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MMAX 15
#define LMAX 105
#define INF 10010
using namespace std;

struct INP {
    int s, e, p, m;
};

int N, M, s, e, p, m;
int cow[LMAX], val[LMAX];

int ret;
INP q[MMAX];

int check(int v) {
    int ret = 0;

    for(int i=0;i<M;i++) {
        if((v & (1<<i)) == 0) continue;

        for(int j=q[i].s;j<=q[i].e;j++) val[j] += q[i].p;
        ret += q[i].m;
    }

    for(int i=1;i<LMAX;i++) {
        if(cow[i] > val[i]) return INF;
    }

    return ret;
}

int main() {
    // 입력
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++) {
        scanf("%d %d %d", &s, &e, &p);
        for(int j=s;j<=e;j++) cow[j] = p;
    }

    for(int i=0;i<M;i++) {
        scanf("%d %d %d %d", &s, &e, &p, &m);
        q[i] = {s, e, p, m};
    }

    // 완전탐색
    ret = INF;
    for(int i=0;i<(1<<M);i++) {
        memset(val, 0, sizeof(val));
        ret = min(ret, check(i));
    }

    printf("%d", ret);
}