#include <iostream>
#include <vector>

using namespace std;

void erathosthenes_sieve(vector<int> &res, int n){
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 4; i <= n; i += 2){
		is_prime[i] = false;
	}
	for(int p = 3; p * p <= n; ++p){
		for(int i = 3 * p; i <= n; i += p){
			is_prime[i] = false;
		}
	}
	for(int i = 0; i <= n; ++i){
		if(is_prime[i]){
			res.push_back(i);
		}
	}
}

long long legendre(long long n, long long p){
	long long ret = 0;
	long long prime_power = p;
	while(n >= prime_power){
		ret += n / prime_power;
		prime_power *= p;
	}
	return ret;
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
	vector<int> primes;
	erathosthenes_sieve(primes, 4000000);
	int n, k, m;
	cin >> n >> k >> m;
	long long ans = 1;
	for(int p : primes){
		if(p > n){
			break;
		}
		long long exp = legendre(n, p) - legendre(k, p) - legendre(n - k, p);
		ans *= power(p, exp, m);
		ans %= m;
	}
	cout << ans;
	return 0;
}
