#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>
#include <algorithm>
#define NMAX 1010
using namespace std;

int N, M, a, b;
vector< int > graph[NMAX*2];

int vi, top, scci, f;
int visited[NMAX*2], scc[NMAX*2];
stack< int > st;

int getSCC(int cur) {
    int ret;

    ret = visited[cur] = vi++;
    st.push(cur);

    for(int nxt:graph[cur]) {
        if(!visited[nxt]) ret = min( ret, getSCC(nxt) );
        else if(!scc[nxt]) ret = min( ret, visited[nxt] );
    }

    if(ret == visited[cur]) {
        scci++;

        while(top != cur) {
            top = st.top();
            st.pop();

            scc[top] = scci;
        }
    }

    return ret;
}

int main() {
    while(scanf("%d %d", &N, &M)!=EOF) {
        // 초기화
        for(int i=1;i<=N*2+1;i++) graph[i].clear();
        memset(scc, 0, sizeof(scc));
        memset(visited, 0, sizeof(visited));

        // 입력
        for(int i=1;i<=M;i++) {
            scanf("%d %d", &a, &b);

            a = a>0 ? a*2:(-a)*2+1;
            b = b>0 ? b*2:(-b)*2+1;

            // a를 만족하지 않는다면 b를 항상 만족하기
            if(a%2 == 0) graph[a+1].push_back(b);
            else graph[a-1].push_back(b);

            // b를 만족하지 않는다면 a를 항상 만족하기
            if(b%2 == 0) graph[b+1].push_back(a);
            else graph[b-1].push_back(a);
        }

        // 상근이 합격 포함시키기
        graph[3].push_back(2);

        // SCC 구하기(Tajan)
        vi = 1;
        for(int i=2;i<=N*2+1;i++) {
            if(!scc[i]) getSCC(i);
        }

        // 2-SAT 만족 여부 확인하기
        f = 1;
        for(int i=1;i<=N and f;i++) {
            if(scc[i*2] == scc[i*2+1]) f = 0;
        }

        // 출력
        if(f) printf("yes\n");
        else printf("no\n");
    }

}