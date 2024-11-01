#include <stdio.h>
#include <vector>
#include <set>
#define NMAX 200010
using namespace std;

int N;
int inp[NMAX][2];

int f, mvCnt, cycle, cnt;
int out[NMAX], check[NMAX];
vector< int > num[NMAX];

void mv(int idx) {
    mvCnt++;
    if(out[idx] == 2) cycle++;
    
    for(int nxt:num[idx]) {
        if(!check[nxt]) {
            check[nxt] = 1;
            mv(nxt);
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d %d", &inp[i][0], &inp[i][1]);
        
        num[inp[i][0]].push_back(inp[i][1]);
        num[inp[i][1]].push_back(inp[i][0]);
        
        out[inp[i][0]]++;
    }
    
    for(int i=1;i<=N and !f;i++) {
        if(check[i] or i == num[i][0]) continue;
        
        mvCnt = cycle = 0;
        check[i] = 1;
        mv(i);
        
        if(cycle >= 2) f = 1;
        else cnt += mvCnt + 1;
    }
    
    if(!f) printf("%d", cnt);
    else printf("-1");
    
}

/*
4
1 2
3 4
3 2
1 4
ans: -1
*/
