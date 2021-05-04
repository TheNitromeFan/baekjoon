#include <iostream>

using namespace std;

int divisors(int n){
	int ret = 1;
	for(int p = 2; p * p <= n; ++p){
		int cnt = 0;
		while(n % p == 0){
			++cnt;
			n /= p;
		}
		ret *= (cnt + 1);
	}
	if(n > 1){
		ret *= 2;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << divisors(n + 1);
	return 0;
}
