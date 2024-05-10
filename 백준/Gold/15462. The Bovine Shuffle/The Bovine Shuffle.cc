#include <stdio.h>
#include <queue>
#define NMAX 100010
using namespace std;

int N, ret;
int inp[NMAX], enter[NMAX];

int front;
queue< int > q;

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d", &inp[i]);
        enter[inp[i]]++;
    }

    ret = N;
    for(int i=1;i<=N;i++) {
        if(!enter[i]) {
            q.push(i);
            ret--;
        }
    }

    while(!q.empty()) {
        front = q.front();
        q.pop();

        enter[inp[front]]--;
        if(!enter[inp[front]]) {
            q.push(inp[front]);
            ret--;
        }
    }

    printf("%d", ret);
}