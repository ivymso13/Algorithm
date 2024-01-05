#include <stdio.h>
#include <deque>
#include <algorithm>
using namespace std;

int N, t;
double ft, bk, ret;
deque< double > dq;

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d", &t);
        dq.push_back(t);
    }
    
    sort(dq.begin(), dq.end());
    
    while(dq.size()>1) {
        ft = dq.front();
        dq.pop_front();
        
        bk = dq.back();
        dq.pop_back();
        
        dq.push_back(bk + ft/2);
    }
    
    ret = dq.front();
    printf("%lf", ret);
}
