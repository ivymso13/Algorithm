#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
#define NMAX 105
#define INF 105*105
using namespace std;

typedef pair<int, int> PAIR;

int N, M, T, ret;
int inp[NMAX][NMAX];

int curX, curY, curF;
int nxtX, nxtY, nxtF;
int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};

queue< PAIR > q;
int dp[NMAX][NMAX][2];

bool safe(int x, int y) { return !(x<0 or y<0 or x>=N or y>=M); }

int main() {
    scanf("%d %d %d", &N, &M, &T);
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            scanf("%d", &inp[i][j]);

            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }

    q.push({0, 0});
    dp[0][0][0] = 0;

    ret = INF;
    while(!q.empty()) {
        curX = q.front().first/M;
        curY = q.front().first%M;
        curF = q.front().second;
        q.pop();

        if(curX == N-1 and curY == M-1) {
            ret = dp[curX][curY][curF];
            break;
        }

        for(int k=0;k<4;k++) {
            nxtX = curX + dx[k];
            nxtY = curY + dy[k];
            if(!safe(nxtX, nxtY) or (!curF and inp[nxtX][nxtY] == 1)) continue;

            if(inp[nxtX][nxtY] == 2) nxtF = 1;
            else nxtF = curF;

            if(dp[curX][curY][curF]+1 < dp[nxtX][nxtY][nxtF]) {
                dp[nxtX][nxtY][nxtF] = dp[curX][curY][curF] + 1;
                q.push({nxtX*M+nxtY, nxtF});
            }
        }
    }

    if(ret == INF or ret > T) printf("Fail");
    else printf("%d", ret);

}