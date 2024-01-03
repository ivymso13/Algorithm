#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#define NMAX 100010
using namespace std;
typedef pair<int, int> PAIR;

int L, A, p;
char d;

int cntL, l, r;
PAIR inp[NMAX], ret[NMAX];
PAIR retL, retR;

bool cmp(PAIR a, PAIR b) { return abs(a.first) < abs(b.first); }

int main() {
    while(scanf("%d %d\n", &L, &A) != EOF) {
        // 초깃값
        cntL = 0;
        l = r = 0;
        retL = retR = {-1, -1};

        // 입력
        for(int i=0;i<A;i++) {
            scanf("%d %c\n", &p, &d);

            if(d == 'R') inp[i] = {p, 1};
            else {
                inp[i] = {p, -1};
                cntL++;
            }
        }

        // 절댓값 기준으로 정렬
        sort(inp, inp+A, cmp);

        for(int i=0;i<A;i++) {
            // 오른쪽 방향 개미만큼 왼쪽으로 떨어짐
            if(i<cntL) {
                // 가장 가까운 왼쪽 방향 개미 찾기 >> 바톤터치
                while(inp[l].second > 0) l++;

                ret[i] = {inp[l++].first, inp[i].first};
                retL = max(retL, ret[i]);
            }
                // 나머지는 오른쪽으로 떨어짐
            else {
                // 가장 가까운 오른쪽 방향 개미 찾기 >> 바톤터치
                while(inp[r].second < 0) r++;

                ret[i] = {L - inp[r++].first, inp[i].first};
                retR = max(retR, ret[i]);
            }
        }

        // 출력
        if(retL.first > retR.first)
            printf("The last ant will fall down in %d seconds - started at %d.\n", retL.first, retL.second);
        else if(retL.first < retR.first)
            printf("The last ant will fall down in %d seconds - started at %d.\n", retR.first, retR.second);
        else
            printf("The last ant will fall down in %d seconds - started at %d and %d.\n", retL.first, min(retL.second, retR.second), max(retL.second, retR.second));
    }
}