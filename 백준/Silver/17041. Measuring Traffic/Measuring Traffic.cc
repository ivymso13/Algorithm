#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> PAIR;

int N, l, r;
string m;

struct tri {
    string mode;
    int l, r;
};
vector< tri > inp;

PAIR st, ed;
PAIR cur;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> m >> l >> r;
        inp.push_back({m, l, r});
    }

    // 종료 지점 구하기
    cur = {0, 1000000};
    for(int i=0;i<N;i++) {
        if(inp[i].mode == "none") {
            cur.first = max(cur.first, inp[i].l);
            cur.second = min(cur.second, inp[i].r);
        }
        else if(inp[i].mode == "on") {
            cur.first += inp[i].l;
            cur.second += inp[i].r;
        }
        else {
            cur.first = max(0, cur.first-inp[i].r);
            cur.second = max(0, cur.second-inp[i].l);
        }
    }
    ed = cur;

    for(int i=N-1;i>=0;i--) {
        if(inp[i].mode == "none") {
            cur.first = max(cur.first, inp[i].l);
            cur.second = min(cur.second, inp[i].r);
        }
        else if(inp[i].mode == "off") {
            cur.first += inp[i].l;
            cur.second += inp[i].r;
        }
        else {
            cur.first = max(0, cur.first-inp[i].r);
            cur.second = max(0, cur.second-inp[i].l);
        }
    }
    st = cur;

    printf("%d %d\n", st.first, st.second);
    printf("%d %d", ed.first, ed.second);
}