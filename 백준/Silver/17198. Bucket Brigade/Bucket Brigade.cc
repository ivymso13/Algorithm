#include <stdio.h>
#include <queue>
#include <utility>
#define NMAX 15
using namespace std;

typedef pair<int, int> PAIR;

char inp[NMAX][NMAX];

PAIR st;
queue< PAIR > q;

int x, y, xx, yy;
int check[NMAX][NMAX];
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};

bool safe(int x, int y) {
    return !(x<0 or y<0 or x>=10 or y>=10);
}

int main() {
    for(int i=0;i<10;i++) {
        scanf("%s", inp[i]);

        for(int j=0;j<10;j++) {
            if(inp[i][j] == 'B') st = {i, j};

            check[i][j] = -1;
        }
    }

    q.push(st);
    check[st.first][st.second] = 0;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if(inp[x][y] == 'L') break;

        for(int k=0;k<4;k++) {
            xx = x + dx[k];
            yy = y + dy[k];
            if(!safe(xx, yy) or inp[xx][yy] == 'R' or check[xx][yy] >= 0) continue;

            check[xx][yy] = check[x][y] + 1;
            q.push({xx, yy});
        }
    }

    printf("%d", check[x][y]-1);
}