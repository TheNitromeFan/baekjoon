#include <iostream>
#include <vector>
#include <unordered_set>

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

void preprocess(bool dp[100001]){
	vector<int> vec;
	unordered_set<int> set;
	erathosthenes_sieve(vec, set, 100000);
	for(int i = 2; i <= 100000; ++i){
		if(set.find(i) != set.end() || set.find(i - 1) != set.end()){
			dp[i] = true;
			continue;
		}
		for(int p : vec){
			if(p + 2 > i){
				break;
			}
			if(!dp[i - p]){
				dp[i] = true;
				break;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool dp[100001] = {};
	preprocess(dp);
	/*
	for(int i = 2; i <= 30; ++i){
		cout << i << ' ' << dp[i] << '\n';
	}
	*/
	int psum[100001] = {};
	for(int i = 2; i <= 100000; ++i){
		psum[i] = psum[i - 1];
		if(!dp[i]){
			++psum[i];
		}
	}
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int a, k;
		cin >> a >> k;
		int x = 2, max_wins = 0;
		for(int i = 2; i + k - 1 <= a; ++i){
			int cmp = psum[i + k - 1] - psum[i - 1];
			if(cmp > max_wins){
				max_wins = cmp;
				x = i;
			}
		}
		cout << max_wins << ' ' << x << '\n';
	}
	return 0;
}
