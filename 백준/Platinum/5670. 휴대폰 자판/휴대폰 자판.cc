#include <stdio.h>
#include <algorithm>
#define NMAX 30
#define WMAX 85
using namespace std;

struct Node {
    Node *child[NMAX];
    bool end;
    int cntChild;
    
    Node() {
        fill(child, child+NMAX, nullptr);
        end = false;
        cntChild = 0;
    }
    
    ~Node() {
        for(int i=0;i<NMAX;i++) delete child[i];
    }
    
    void insert(char *val) {
        if(*val == '\0') end = true;
        else {
            int nxt = *val-'a';
            
            if(!child[nxt]) {
                child[nxt] = new Node();
                cntChild++;
            }
            
            child[nxt]->insert(val+1);
        }
    }
    
    int check(int cnt) {
        if(cntChild == 0) return cnt;
        
        int ret;
        
        if(end) ret = cnt;
        else ret = 0;
        
        for(int i=0;i<NMAX;i++) {
            if(!child[i]) continue;
            
            if(!end and cntChild == 1) ret += child[i]->check(cnt);
            else ret += child[i]->check(cnt+1);
        }
        
        return ret;
    }
};

int N, ret;
char word[WMAX];

int main() {
    while(scanf("%d", &N) != EOF) {
        Node *root = new Node();
        for(int i=0;i<N;i++) {
            scanf("%s", word);
            
            root->insert(word);
        }
        
        if(root->cntChild == 1) ret = root->check(1);
        else ret = root->check(0);
        
        printf("%.2lf\n", (double)ret/N);
        
        delete root;
    }
}
