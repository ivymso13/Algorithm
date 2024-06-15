#include <stdio.h>
#include <stack>
#define NMAX 500010
using namespace std;

int N;
int inp[NMAX], ans[NMAX];

int top;
stack< int > st;

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%d", &inp[i]);

    for(int i=N;i>=1;i--) {
        while(!st.empty() and st.top() <= inp[i]) st.pop();

        ans[i] = (int)st.size();
        st.push(inp[i]);
    }

    for(int i=1;i<=N;i++) printf("%d ", ans[i]);
}