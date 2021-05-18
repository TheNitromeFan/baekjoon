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
	erathosthenes_sieve(primes, 1120);
	long long dp[1125][15] = {}; // dp[sum][number of primes]
	dp[0][0] = 1;
	for(unsigned i = 0; i < primes.size(); ++i){
		for(int j = 1120; j >= primes[i]; --j){
			for(int k = 1; k <= 14; ++k){
				dp[j][k] += dp[j - primes[i]][k - 1];
			}
		}
	}
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, k;
		cin >> n >> k;
		cout << dp[n][k] << '\n';
	}
	return 0;
}
