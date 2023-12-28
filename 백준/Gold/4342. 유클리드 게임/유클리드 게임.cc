#include <stdio.h>
typedef long long INT;

INT a, b, ret;

int sv(INT a, INT b) {
    if(a < b) return sv(b, a);

    if(a%b == 0) return 1;
    else {
        int f = sv(b, a%b);

        if(a < b*2) return 1-f;
        else return 1;
    }
}

int main() {
    while(1) {
        scanf("%lld %lld", &a, &b);
        if(!a and !b) break;

        ret = sv(a, b);

        if(ret) printf("A wins\n");
        else printf("B wins\n");
    }
}
/*
21 17 -- 0
17 4 -- 1
4 1 -- 1


197 30 -- 1
30 17 -- 1
17 13 -- 0
13 4 -- 1
4 1 -- 1
*/