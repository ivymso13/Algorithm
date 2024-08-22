#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 10010
#define NMAX 100010
using namespace std;

int N;
int inp[NMAX], pMin[NMAX], pSum[NMAX];

int vmin, ret;
double vmax, tmp;
vector< int > ans;

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d", &inp[i]);
        pSum[i] = pSum[i-1] + inp[i];
    }

    vmin = INF;
    for(int i=N;i>=1;i--) pMin[i] = vmin = min(vmin, inp[i]);

    vmax = 0;
    for(int i=1;i<N-1;i++) {
        tmp = (double)(pSum[N] - pSum[i] - pMin[i+1])/(N-i-1);

        if(vmax < tmp) {
            ans.clear();
            ans.push_back(i);

            vmax = tmp;
        }
        else if(vmax == tmp) ans.push_back(i);

    }

    for(int val:ans) printf("%d\n", val);
}