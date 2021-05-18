#include <iostream>

using namespace std;

bool is_prime(long long n){
	if(n == 1){
		return false;
	}
	for(long long p = 2; p * p <= n; ++p){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

long long power(long long base, long long exp, long long mod){
	if(exp == 0){
		return 1;
	}else if(exp % 2 == 0){
		return power(base * base % mod, exp / 2, mod);
	}else{
		return power(base * base % mod, exp / 2, mod) * base % mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		long long p, a;
		cin >> p >> a;
		if(p == 0 && a == 0){
			break;
		}
		cout << (!is_prime(p) && power(a, p, p) == a ? "yes" : "no") << '\n';
	}
	return 0;
}
