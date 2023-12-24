#include <iostream>
#define NMAX 505
using namespace std;

string inp;
int rm, len;
int check[NMAX], cnt[2];

int main() {
    cin >> inp;

    len = inp.length();
    for(int i=0;inp[i]!='\0';i++) {
        cnt[inp[i]-'0']++;
        check[i] = 1;
    }

    // 뒤에서부터 0 제거하기
    rm = cnt[0]/2;
    for(int i=len-1;i>=0 and rm>0;i--) {
        if(inp[i] != '0') continue;

        rm--;
        check[i] = -1;
    }

    // 앞에서부터 1 제거하기
    rm = cnt[1]/2;
    for(int i=0;i<len and rm>0;i++) {
        if(inp[i] != '1') continue;

        rm--;
        check[i] = -1;
    }


    // 출력
    for(int i=0;i<len;i++) {
        if(check[i]<0) continue;
        cout << inp[i];
    }
}