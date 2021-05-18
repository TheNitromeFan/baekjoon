#include <iostream>
#include <vector>
#define MOD 987654321

using namespace std;

void erathosthenes_sieve(vector<int> &res, int n){
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 4; i <= n; i += 2){
		is_prime[i] = false;
	}
	for(int p = 3; p * p <= n; p += 2){
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> primes;
	erathosthenes_sieve(primes, 1000000);
	int n;
	cin >> n;
	long long ans = 1;
	for(int p : primes){
		if(p > n){
			break;
		}
		long long prime_power = 1;
		while(prime_power * p <= n){
			prime_power *= p;
		}
		ans *= prime_power;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}
