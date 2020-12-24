#include <iostream>

using namespace std;

long long depressed(int m, int n){
	if(m <= 0){
		return 0;
	}
	int q = m / (n + 1), r = m % (n + 1);
	return (long long)(q + 1) * (q + 2) * (2 * q + 3) / 6 * r
	+ (long long)q * (q + 1) * (2 * q + 1) / 6 * (n + 1 - r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		int hi;
		cin >> hi;
		m -= hi + 1;
	}
	cout << depressed(m, n);
	return 0;
}
