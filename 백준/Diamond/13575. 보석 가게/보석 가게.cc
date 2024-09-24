#include <stdio.h>
#include <math.h>
#include <vector>
#include <complex>
#define NMAX 1024
using namespace std;
typedef complex< double > cpx;

int N, K, t;
vector< cpx > ret;
vector< cpx > inp(NMAX);

// PI값
const double PI = acos(-1);

void FFT(vector< cpx > &v, bool f) {
    int n, bit;

    n = v.size();
    for(int i=1,j=0;i<n;i++) {
        for(bit=n/2;j>=bit;bit/=2) j -= bit;

        j += bit;
        if(i < j) swap(v[i], v[j]);
    }

    for(int len=1;len<n;len*=2) {
        double d = f ? PI/len : -PI/len;
        cpx t = cpx(cos(d), sin(d));

        for(int i=0;i<n;i+=len*2) {
            cpx theta = cpx(1, 0);
            for(int j=0;j<len;j++) {
                cpx even, odd;
                even = v[i+j], odd = v[i+j+len];

                v[i+j] = even + theta*odd;
                v[i+j+len] = even - theta*odd;

                theta *= t;
            }
        }
    }

    // iDFT
    if(f) {
        for(int i=0;i<n;i++) v[i] /= n;
    }
}

vector< cpx > mul(vector< cpx > a, vector< cpx > b) {
    // 2^n <= sz 구하기 및 정규화
    int sz;
    for(sz=2;sz<a.size()+b.size();sz*=2);

    a.resize(sz);
    b.resize(sz);

    FFT(a, 0);
    FFT(b, 0);

    // 결과 계산하기
    for(int i=0;i<sz;i++) a[i] = a[i]*b[i];

    // 켤레복소수를 활용한 iDFT
    FFT(a, 1);

    for(int i=0;i<sz;i++) {
        if(round(a[i].real()) > 0) a[i] = cpx(1, 0);
        else a[i] = cpx(0, 0);
    }

    return a;

}

int main() {
    scanf("%d %d", &N, &K);
    for(int i=1;i<=N;i++) {
        scanf("%d", &t);
        inp[t] = cpx(1, 0);
    }

    // 거듭제곱 분할정복
    ret.push_back(cpx(1, 0));
    while(K > 0) {
        if(K%2 == 1) ret = mul(ret, inp);

        inp = mul(inp, inp);
        K /= 2;
    }

    for(int i=1;i<ret.size();i++) {
        if(round(ret[i].real()) > 0) printf("%d ", i);
    }
}