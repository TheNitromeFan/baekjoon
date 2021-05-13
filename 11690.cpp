#include <iostream>
#include <vector>
#define MOD (1LL << 32)

using namespace std;

void erathosthenes_sieve(vector<long long> &res, int limit){
	vector<bool> is_prime(limit + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 4; i <= limit; i += 2){
		is_prime[i] = false;
	}
	for(int p = 3; p * p <= limit; p += 2){
		for(int i = 3 * p; i <= limit; i += p){
			is_prime[i] = false;
		}
	}
	for(int i = 0; i <= limit; ++i){
		if(is_prime[i]){
			res.push_back(i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<long long> primes;
	erathosthenes_sieve(primes, 100000000);
	int n;
	cin >> n;
	long long ans = 1;
	for(long long p : primes){
		if(p > n){
			break;
		}
		long long power = p;
		while(power * p <= n){
			power *= p;
		}
		ans *= power % MOD;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}
