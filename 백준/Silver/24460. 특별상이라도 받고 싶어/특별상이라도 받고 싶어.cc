#include <stdio.h>
#include <vector>
#include <algorithm>
#define NMAX 1<<11
using namespace std;

int N;
int inp[NMAX][NMAX];

int sv(int x, int y, int d) {
    if(d == 1) return inp[x][y];

    vector< int > tmp;
    for(int i=x;i<x+d;i+=d/2) {
        for(int j=y;j<y+d;j+=d/2) {
            tmp.push_back({sv(i, j, d/2)});
        }
    }

    sort(tmp.begin(), tmp.end());

    return tmp[1];
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            scanf("%d", &inp[i][j]);
        }
    }

    printf("%d", sv(0, 0, N));
}