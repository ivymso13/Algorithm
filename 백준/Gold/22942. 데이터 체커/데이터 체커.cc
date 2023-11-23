#include <stdio.h>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> PAIR;

int N, a, b;
vector< int > num;
vector< PAIR > inp;

int f;
PAIR top;
stack< PAIR > st;

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d %d", &a, &b);
        
        num.push_back(a-b);
        num.push_back(a+b);
        
        inp.push_back({a-b, i});
        inp.push_back({a+b, -i});
    }
    
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    
    if(num.size() != N*2) f = 1;
    else{
        sort(inp.begin(), inp.end());
        
        for(int i=0;i<2*N and !f;i++) {
            if(inp[i].second > 0) st.push(inp[i]);
            else {
                if(st.empty()) f = 1;
                else {
                    top = st.top();
                    st.pop();
                
                    if(top.second != -inp[i].second) f = 1;
                    
                }
            }
        }
    }
    
    printf(f == 0 ? "YES":"NO");
}
