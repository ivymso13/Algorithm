#include <stdio.h>
#include <vector>
#define NMAX 300010
using namespace std;
typedef long long INT;

int N, x, y;
vector< int > graph[NMAX];


INT a, b;

void dfs(int idx, int prev) {
    // a: 'ㄷ'트리 / b: 'ㅈ'트리
    
    // 'ㅈ'트리는 간선이 3개 이상인 경우
    INT sz = graph[idx].size();
    if(sz >= 3) b += (sz*(sz-1)*(sz-2))/6;
    
    for(int child:graph[idx]) {
        if(child == prev) continue;
        
        // 'ㄷ'트리는 두 정점에 간선이 있는 경우
        INT sz2 = graph[child].size();
        a += (sz-1)*(sz2-1);
        
        dfs(child, idx);
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1;i<N;i++) {
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    dfs(1, 0);
    
    if(a > b*3) printf("D");
    else if(a < b*3) printf("G");
    else printf("DUDUDUNGA");
}
