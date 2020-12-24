#include <iostream>
#include <vector>

using namespace std;

vector<long long> a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};

long long power(long long base, long long exponent, long long mod){
	if(exponent == 0){
		return 1;
	}else if(exponent % 2 == 0){
		long long x = power(base, exponent / 2, mod);
		return x * x % mod;
	}else{
		long long x = power(base, exponent / 2, mod);
		return x * x % mod * base % mod;
	}
}

bool miller_rabin(long long n, long long b){ // true for probable prime, false for composite
	long long d = n - 1;
	while(true){
		// cout << power(b, d, n) << '\n';
		if(power(b, d, n) == n - 1){
			return true;
		}
		if(d % 2 == 1){
			break;
		}
		d /= 2;
	}
	long long x = power(b, d, n);
	return x == n - 1 || x == 1;
}

bool is_prime(unsigned long long n){
	if(n == 1){
		return false;
	}else if(n == 2){
		return true;
	}
	for(int x : a){
		if(x % n == 0){
			continue;
		}
		if(!miller_rabin(n, x)){
			// cout << n << ' ' << x << '\n';
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		unsigned long long z;
		cin >> z;
		if(is_prime(2 * z + 1)){
			// cout << z << '\n';
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
