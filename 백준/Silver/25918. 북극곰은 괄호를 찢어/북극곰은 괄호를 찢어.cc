#include <stdio.h>
#include <stack>
#include <utility>
#define NMAX 200'010
#define PAIR pair<char, int>
using namespace std;

int N;
char inp[NMAX];

int ret, cnt;

PAIR top;
stack< PAIR > st;

int main() {
    scanf("%d", &N);
    scanf("%s", inp);
    
    for(int i=0;i<N;i++) {
        if(st.empty()) st.push({inp[i], 1});
        else {
            top = st.top();
            
            if(top.first == inp[i]) st.push({inp[i], top.second+1});
            else {
                ret = max( ret, top.second );
                st.pop();
            }
        }
    }
    
    if(st.empty()) printf("%d", ret);
    else printf("-1");
}
/*
14
(()()((()))())
ans: 4
*/
