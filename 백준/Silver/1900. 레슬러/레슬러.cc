#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PAIR;

int N, a, b;
vector< PAIR > inp;

int valA, valB;
vector< PAIR > ret;

int main() {
    // 입력
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d %d", &a, &b);
        inp.push_back({a, b});
        ret.push_back({0, i});
    }

    // 경기 결과 저장
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            valA = inp[i].first + inp[i].second*inp[j].first;
            valB = inp[j].first + inp[j].second*inp[i].first;

            if(valA == valB) continue;
            else if(valA < valB) ret[i].first++;
            else ret[j].first++;
        }
    }

    // 승수로 정렬
    sort(ret.begin(), ret.end());

    // 출력
    for(PAIR p:ret) printf("%d\n", p.second);
}