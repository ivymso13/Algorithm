#include <iostream>
#define NMAX 1000000+1
using namespace std;

long long int n, m, start;
long long int a, b, cnt;
int check[NMAX];

int main() {
	cin >> n >> m;
	
	
	for(long long int k=2;k*k<=m;k++) {
		if(k*k >= n and check[(k*k)-n]) continue;
		
		if(n%(k*k) == 0) start = n/(k*k);
		else start = n/(k*k)+1;
		
		for(long long int j=start;(k*k)*j<=m;j++) check[(k*k)*j-n] = 1;
	}
	
	for(long long int k=n;k<=m;k++) {
		if(!check[k-n]) cnt++;
	}
	
	cout << cnt;
}