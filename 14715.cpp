#include <iostream>

using namespace std;

int prime_power_factors(int n){
	int ret = 0;
	for(int p = 2; p * p <= n; ++p){
		while(n % p == 0){
			++ret;
			n /= p;
		}
	}
	if(n > 1){
		++ret;
	}
	return ret;
}

int divisions(int n){
	int x = 1;
	int ret = 0;
	while(x < n){
		++ret;
		x *= 2;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	cout << divisions(prime_power_factors(k));
	return 0;
}
