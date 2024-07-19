#include <stdio.h>
#define MOD 1000000007
typedef long long INT;

struct Node {
    INT left, right, sz;
    INT ret;
    
    Node(){ left = right = sz = ret = 1; }
};

int N, a, b;
Node tree[100010];

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d %d", &a, &b);
        
        // tree[i].ret : S[i] 값
        // tree[a].ret + tree[b].ret : 왼쪽과 오른쪽 자식만 사용한 경우
        // tree[a].right * tree[b].sz + tree[b].left * tree[a].sz : 왼쪽과 오른쪽 자식을 겹쳐서 사용한 경우
        // 1을 빼는 이유 : 예외사항(모든 말단 노드를 포함하는 경우) 처리
        tree[i].ret = (tree[a].ret + tree[b].ret)%MOD;
        tree[i].ret = (tree[i].ret + (tree[a].right * tree[b].sz) + (tree[b].left * tree[a].sz) - 1)%MOD;
        
        // tree[i].sz : 말단 노드의 개수
        tree[i].sz = (tree[a].sz + tree[b].sz)%MOD;
        
        // tree[i].left : 맨 왼쪽 자식을 포함하는 f(a, b)의 값
        // tree[b].left + tree[b].sz : tree[a]를 모두 사용하고, tree[b]의 일부분을 사용할 때의 f(a, b) 값
        // >> tree[a]는 모두 사용하기 때문에 항상 1이며, tree[b]의 말단 노드 개수만큼 1을 더해줌
        tree[i].left = (tree[a].left + (tree[b].left + tree[b].sz) - 1)%MOD;
        
        // tree[i].right : 맨 오른쪽 자식을 포함하는 f(a, b)의 값
        // tree[a].right + tree[a].sz : tree[b]를 모두 사용하고, tree[a]의 일부분을 사용할 때의 f(a, b) 값
        // >> tree[b]는 모두 사용하기 때문에 항상 1이며, tree[a]의 말단 노드 개수만큼 1을 더해줌
        tree[i].right = (tree[b].right + tree[a].right + (tree[a].sz - 1))%MOD;
        
        printf("%lld\n", tree[i].ret);
    }
    
}
