#include <stdio.h>
#include <string.h>
#define NMAX 55

char inp[NMAX];
int cnt[3];

int f;
int dp[NMAX][NMAX][NMAX][3][3];

struct Data {
    int a, b, c, b1, b2;
};
Data trace[NMAX][NMAX][NMAX][3][3];

int sv(int A, int B, int C, int b1, int b2) {
    if(A<0 or B<0 or C<0) return 0;

    if(dp[A][B][C][b1][b2] >= 0) return dp[A][B][C][b1][b2];
    else if(!A and !B and !C) return dp[A][B][C][b1][b2] = 1;
    else {
        int ret = 0;
        Data cur = {A, B, C, b1, b2};

        if(sv(A-1, B, C, 0, b1)) {
            ret = 1;
            trace[A-1][B][C][0][b1] = cur;
        }

        if(b1 != 1 and sv(A, B-1, C, 1, b1)) {
            ret = 1;
            trace[A][B-1][C][1][b1] = cur;
        }

        if(b1 != 2 and b2 != 2 and sv(A, B, C-1, 2, b1)) {
            ret = 1;
            trace[A][B][C-1][2][b1] = cur;
        }

        return dp[A][B][C][b1][b2] = ret;
    }
}

void print(int A, int B, int C, int b1, int b2) {
    if(A == cnt[0] and B == cnt[1] and C == cnt[2]) return;

    print(trace[A][B][C][b1][b2].a, trace[A][B][C][b1][b2].b, trace[A][B][C][b1][b2].c, trace[A][B][C][b1][b2].b1, trace[A][B][C][b1][b2].b2);
    switch(b1) {
        case 0:
            printf("A");
            break;
        case 1:
            printf("B");
            break;
        default:
            printf("C");
    }
}

int main() {
    scanf("%s", inp);
    for(int i=0;inp[i]!='\0';i++) cnt[inp[i]-'A']++;

    memset(dp, -1, sizeof(dp));
    f = sv(cnt[0], cnt[1], cnt[2], 0, 0);


    if(f == 0) printf("-1");
    else {
        for(int i=0;i<3 and f;i++) {
            for(int j=0;j<3 and f;j++) {
                if(dp[0][0][0][i][j] == 1) {
                    print(0, 0, 0, i, j);
                    f = 0;
                }
            }
        }
    }

}