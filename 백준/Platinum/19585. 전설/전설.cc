#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#define NMAX 1010
using namespace std;


int C, N, Q;
int tlen, f;
int check[NMAX*2];

struct Node {
    map< char, Node* > nxt;
    bool end;
    
    Node() {
        nxt.clear();
        end = false;
    }
    
    void insert(char *val) {
        if(*val == '\0') end = true;
        else {
            if(!nxt[*val]) nxt[*val] = new Node();
            nxt[*val]->insert(val+1);
        }
    }
    
    void search(char *val, int idx, int d) {
        if(end) check[idx]++;
        
        if(*val == '\0' or !nxt[*val]) return;
        else nxt[*val]->search(val+1, idx+d, d);
    }
};

int main() {
    // 초기화
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Node *root[2];
    for(int j=0;j<2;j++) root[j] = new Node();
    
    // 입력
    cin >> C >> N;
    for(int i=0;i<C+N;i++) {
        char inp[NMAX];
        cin >> inp;
        
        if(i<C) root[0]->insert(inp);
        else {
            reverse(inp, inp+strlen(inp));
            root[1]->insert(inp);
        }
    }
    
    // 쿼리
    cin >> Q;
    for(int i=0;i<Q;i++) {
        // 초기화
        memset(check, 0, sizeof(check));
        
        // 입력
        char team[NMAX*2];
        cin >> team;
        tlen = (int)strlen(team);
        
        // 순서대로 탐색 & 역순으로 탐색
        root[0]->search(team, 0, 1);
        
        reverse(team, team+tlen);
        root[1]->search(team, tlen, -1);
        
        // 서로 만나는 지점이 있으면 종료
        f = 0;
        for(int i=0;i<tlen;i++) {
            if(check[i] == 2) {
                f = 1;
                break;
            }
        }
        
        // 출력
        if(f) cout << "Yes\n";
        else cout << "No\n";
    }
}
