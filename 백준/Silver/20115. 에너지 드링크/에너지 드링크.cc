#include <stdio.h>
#include <algorithm>
#define NMAX 100010
using namespace std;

int N, t;
double inp[NMAX];

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%lf", &inp[i]);
    
    sort(inp+1, inp+N+1);
    
    for(int i=1;i<N;i++) inp[N] += inp[i]/2;
    
    printf("%lf", inp[N]);
}
