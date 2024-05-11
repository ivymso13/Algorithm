#include <stdio.h>
#include <vector>
#define INF 987654321
using namespace std;

int N, t, tot, ret;
vector< int > inp;

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &t);

        inp.push_back(t);
        tot += t;
    }

    ret = INF;
    for(int i=0;i<N;i++) {
        int idx, tmp, tmpTot;

        idx = i;
        tmp = 0;
        tmpTot = tot;
        do {
            tmpTot -= inp[idx];
            tmp += tmpTot;

            idx = (idx+1)%N;
        }while(idx != i);

        ret = min(ret, tmp);
    }

    printf("%d", ret);
}