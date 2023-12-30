#include <iostream>
#include <map>
#include <algorithm>
#define SWAP(a,b,t)(t=a, a=b, b=t)
using namespace std;

int N, M, T;
string a, b, inp;

char t;
map< char, int > check;

int main() {
    cin >> N >> M;
    cin >> a;
    cin >> b;
    cin >> T;

    reverse(a.begin(), a.end());
    inp = a + b;

    for(int i=0;i<N+M;i++) {
        if(i<N) check[inp[i]] = 1;
        else check[inp[i]] = -1;
    }

    while(T--) {
        for(int i=0;i<N+M-1;i++) {
            if(check[inp[i]] > 0 and check[inp[i+1]] < 0) {
                SWAP(inp[i], inp[i+1], t);
                i++;
            }
        }
    }

    for(char c:inp) cout << c;
}