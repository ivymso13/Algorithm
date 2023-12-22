#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#define NMAX 100'010
using namespace std;

int N, M, x, y;
vector< int > graph[NMAX];

int num, sccNum, top;
int visited[NMAX], scc[NMAX];
stack< int > st;

int cnt;
int enter[NMAX];

int getSCC(int idx) {
    int ret;

    ret = visited[idx] = num++;
    st.push(idx);

    for(int nxt:graph[idx]) {
        if(visited[nxt] == 0) ret = min( ret, getSCC(nxt) );
        else if(scc[nxt] == 0) ret = min( ret, visited[nxt] );
    }

    if(ret == visited[idx]) {
        sccNum++;

        while(1) {
            top = st.top();
            st.pop();

            scc[top] = sccNum;
            if(top == idx) break;
        }
    }

    return ret;
}

int main() {
    // 입력
    scanf("%d %d", &N, &M);
    for(int i=1;i<=M;i++) {
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
    }

    // SCC 구하기
    num = 1;
    for(int i=1;i<=N;i++) {
        if(!visited[i]) getSCC(i);
    }

    // SCC 기준으로 그래프 재구성하기(sccGraph)
    for(int i=1;i<=N;i++) {
        for(int nxt:graph[i]) {
            if(scc[i] == scc[nxt]) continue;

            enter[scc[nxt]]++;
        }
    }

    // 진입 차수가 0인 노드 확인 > -1로 초기화하여 중복 제거
    for(int i=1;i<=N;i++) {
        if(!enter[scc[i]]) {
            cnt++;
            enter[scc[i]] = -1;
        }
    }

    // 출력
    printf("%d", cnt);
}