#include <iostream>
using namespace std;

int N;
string inp, A, B;

string check(int l, int r) {
    int endL, endR, f;
    string ret;

    endL = r-1; endR = N-1;
    f = 0;
    ret = "";

    while(l<=endL and r<=endR) {
        if(inp[l] == inp[r]) {
            ret += inp[l];
            l++; r++;
        }
        else {
            f++;
            if(f > 1) return "\0";
            else if(endL == N/2) l++;
            else r++;
        }
    }

    return ret;
}

int main() {
    cin >> N;
    cin >> inp;

    if(N%2 == 0) cout << "NOT POSSIBLE";
    else {
        A = check(0, N/2);
        B = check(0, N/2+1);

        if(A == B) {
            if(A == "\0") cout << "NOT POSSIBLE";
            else cout << A;
        }
        else {
            if(A != "\0" and B != "\0") cout << "NOT UNIQUE";
            else if(A == "\0") cout << B;
            else cout << A;
        }
    }
}