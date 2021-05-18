#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void erathosthenes_sieve(vector<int> &primes_vec, unordered_set<int> &primes_set, int n){
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
			primes_vec.push_back(i);
			primes_set.insert(i);
		}
	}
}

int q(vector<int> &primes_vec, unordered_set<int> &primes_set, int n){
	if(n == 1){
		return -1;
	}else if(primes_set.find(n) != primes_set.end()){
		return -2;
	}
	int factors = 0;
	for(int p : primes_vec){
		if(p * p > n){
			break;
		}
		while(n % p == 0){
			++factors;
			n /= p;
		}
	}
	if(n > 1){
		++factors;
	}
	return factors - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> vec;
	unordered_set<int> set;
	erathosthenes_sieve(vec, set, 1000000);
	/*
	for(int i = 1; i <= 20; ++i){
		cout << q(vec, set, i) << ' ';
	}
	*/
	int dp[1000001];
	dp[0] = 0;
	for(int i = 1; i <= 1000000; ++i){
		dp[i] = dp[i - 1] + q(vec, set, i);
	}
	int t = 0;
	while(true){
		int lower, upper;
		cin >> lower >> upper;
		if(lower == -1 && upper == -1){
			break;
		}
		++t;
		int low[1000001], high[1000001];
		low[lower] = dp[lower - 1];
		for(int i = lower + 1; i <= upper; ++i){
			low[i] = min(low[i - 1], dp[i - 1]);
		}
		high[upper] = dp[upper];
		for(int i = upper - 1; i >= lower; --i){
			high[i] = max(high[i + 1], dp[i]);
		}
		int ans = -1000000000;
		for(int i = lower; i <= upper; ++i){
			ans = max(ans, high[i] - low[i]);
		}
		cout << t << ". " << ans << '\n';
	}
	return 0;
}
