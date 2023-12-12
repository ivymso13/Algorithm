#include <iostream>
#include <algorithm>
#define SWAP(a,b,t)(t=a, a=b, b=t)
using namespace std;

string a, b, t, ret;
char c;

int main() {
    cin >> a;
    cin >> c;
    cin >> b;
    
    if(c == '+') {
        if(a.length() == b.length()) ret = "2" + a.substr(1);
        else {
            if(a.length() < b.length()) SWAP(a,b,t);
            
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            for(int i=0;i<a.length();i++) {
                if(a[i] == '1') ret += "1";
                else if(i >= b.length()) ret += "0";
                else if(b[i] == '1') ret += "1";
                else ret += "0";
            }
            
            reverse(ret.begin(), ret.end());
        }
    }
    else {
        ret = "1";
        for(int i=a.length()+b.length()-2;i>=1;i--) ret += "0";
    }
    
    cout << ret;
}
