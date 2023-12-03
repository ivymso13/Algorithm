#include <stdio.h>
#define NMAX 505

int R, C;
char inp[NMAX][NMAX];

int f;
int di[]={-1,0,1,0}, dj[]={0,-1,0,1};
char ans[NMAX][NMAX];

bool safe(int x, int y) { return !(x<0 or y<0 or x>=R or y>=C); }

int main() {
    scanf("%d %d", &R, &C);
    for(int i=0;i<R;i++) {
        scanf("%s", inp[i]);
        
        for(int j=0;j<C;j++) ans[i][j] = '.';
    }
    
    f = 1;
    for(int i=0;i<R and f;i++) {
        for(int j=0;j<C and f;j++) {
            if(inp[i][j] == 'S') {
                ans[i][j] = 'S';
                for(int k=0;k<4;k++) {
                    int ii = i+di[k];
                    int jj = j+dj[k];
                    if(!safe(ii, jj)) continue;
                    
                    // 주변 확인하기
                    // (1) 양이 있는 경우 / (2) 늑대가 있는 경우 / (3) 그 외
                    if(inp[ii][jj] == 'S') continue;
                    else if(inp[ii][jj] == 'W') f = 0;
                    else ans[ii][jj] = 'D';
                }
            }
        }
    }
    
    printf("%d\n", f);
    if(f > 0) {
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                if(ans[i][j] == '.') printf("%c", inp[i][j]);
                else printf("%c", ans[i][j]);
            }
            printf("\n");
        }
    }
}
