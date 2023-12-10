#include <stdio.h>
#include <algorithm>
#define NMAX 15
using namespace std;


struct Node {
    Node *child[NMAX];
    bool end, isChild;
    
    Node() {
        fill(child, child+NMAX, nullptr);
        end = isChild = false;
    }
    
    // 노드 추가 및 일관성 확인
    // 일관성이 있다: 모든 노드가 말단 노드에서 끝난다.
    // >> (end == true) and (isChild == false)
    bool insert(char* val) {
        if(*val == '\0') {
            end = true;
            
            // 자식의 유무로 일관성 판별 가능
            return !isChild;
        }
        else {
            int nxt = *val - '0';
            if(!child[nxt]) child[nxt] = new Node();
            
            isChild = true;
            
            // 일관성 판별하기
            return (!end and child[nxt]->insert(val+1));
        }
    }
};

int T, N;
char tel[NMAX];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        
        bool ret = true;
        Node *root = new Node();
        for(int i=1;i<=N;i++) {
            scanf("%s", tel);
            
            ret = (ret & root->insert(tel));
        }
        
        printf(ret ? "YES\n":"NO\n");
    }
}
