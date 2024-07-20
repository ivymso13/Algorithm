#include <stdio.h>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define INT long long
#define INF 987654321
#define PAIR pair< INT, int >
#define SWAP(a, b)(a=a^b, b=a^b, a=a^b)
using namespace std;

struct OP {
    int l, r, c;
};

int N, M, t;
int l, r, c;
vector< int > inp;
vector< OP > op;

int cnt, ret;
INT num, idx, nxt;
queue< INT > q;
vector< int > tmp;
map< INT, int > check;

vector< int > sep(INT val) {
    int t;
    stack< int > st;
    vector< int > ret;
    
    while(val > 0) {
        t = val%10;
        if(t == 0) {
            t = 10;
            val /= 10;
        }
        
        st.push(t);
        val /= 10;
    }
    
    while(!st.empty()) {
        ret.push_back(st.top());
        st.pop();
    }
    
    return ret;
}

INT combine(vector< int > v) {
    INT num = 0;
    
    for(int i=0;i<v.size();i++) {
        if(v[i] == 10) num = num*100 + v[i];
        else num = num*10 + v[i];
    }
    
    return num;
}

bool isFin(vector< int > v) {
    for(int i=1;i<v.size();i++) {
        if(v[i-1] > v[i]) return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &t);
        inp.push_back(t);
    }
    
    scanf("%d", &M);
    for(int i=0;i<M;i++) {
        scanf("%d %d %d", &l, &r, &c);
        op.push_back({l-1, r-1, c});
    }
    
    num = combine(inp);
    q.push(num);
    ret = INF;
    
    while(!q.empty()) {
        idx = q.front();
        cnt = check[q.front()];
        q.pop();
        
        tmp = sep(idx);
        if(isFin(tmp)) ret = min(ret, cnt);
        else {
            for(int i=0;i<M;i++) {
                SWAP(tmp[op[i].l], tmp[op[i].r]);
                nxt = combine(tmp);
                
                if(!check[nxt] or cnt + op[i].c < check[nxt]) {
                    check[nxt] = cnt + op[i].c;
                    q.push(nxt);
                }
                
                SWAP(tmp[op[i].l], tmp[op[i].r]);
            }
        }
    }
    
    printf("%d", ret==INF ? -1:ret);
}
