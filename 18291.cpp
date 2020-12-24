#include <iostream>
#define MOD 1000000007

using namespace std;

long long power(long long base, int exp, long long mod){
	if(exp == 0){
		return 1;
	}else if(exp % 2 == 0){
		long long x = power(base, exp / 2, mod);
		return x * x % mod;
	}else{
		long long x = power(base, exp / 2, mod);
		return x * x % mod * base % mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		if(n > 1){
			cout << power(2, n - 2, MOD) << '\n';
		}else{
			cout << 1 << '\n';
		}
	}
	return 0;
}
