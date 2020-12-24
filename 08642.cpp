#include <iostream>

using namespace std;

long long m(int n){
	long long ret = 1;
	for(int p = 2; p * p <= n; ++p){
		int cnt = 0;
		while(n % p == 0){
			ret *= p;
			++cnt;
			n /= p;
		}
		if(cnt % 2 == 1){
			ret *= p;
		}
	}
	if(n > 1){
		ret *= n;
		ret *= n;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << m(n);
	return 0;
}
