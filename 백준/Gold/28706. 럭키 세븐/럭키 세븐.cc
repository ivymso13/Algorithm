#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
#define PAIR pair<int, int>
using namespace std;

int T, N, v1, v2;
char op[2];
int inp[200010][2];

int dp[200010][7];

int getNxt(int val, int inp) { return inp>0 ? val+inp:val*(-inp); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T--) {
        // init
        for(int i=0;i<=N;i++) {
            for(int j=0;j<7;j++) dp[i][j] = 0;
        }
        
        // input
        cin >> N;
        for(int i=0;i<N;i++) {
            cin >> op[0] >> inp[i][0] >> op[1] >> inp[i][1];
            for(int j=0;j<2;j++) inp[i][j] = (op[j]=='+' ? inp[i][j]:(-inp[i][j]));
        }
        
        // sv
        dp[0][1] = 1;
        for(int idx=0;idx<N;idx++) {
            for(int k=0;k<7;k++) {
                for(int j=0;j<2;j++) {
                    dp[idx+1][getNxt(k, inp[idx][j])%7] |= dp[idx][k];
                }
            }
        }
        
        // print
        if(dp[N][0]) cout << "LUCKY\n";
        else cout << "UNLUCKY\n";
    }
}
