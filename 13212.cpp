#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool has_4_consec_digits(long long m){
	while(m >= 1111){
		if(m % 10 == m / 10 % 10 && m % 10 == m / 100 % 10 && m % 10 == m / 1000 % 10){
			return true;
		}
		m /= 10;
	}
	return false;
}

void generate_primes(int limit, vector<int> &dest){
	vector<bool> is_prime(limit + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 4; i <= limit; i += 2){
		is_prime[i] = false;
	}
	for(int p = 3; p * p <= limit; p += 2){
		for(int i = p * p; i <= limit; i += p){
			is_prime[i] = false;
		}
	}
	for(int j = 0; j <= limit; ++j){
		if(is_prime[j]){
			dest.push_back(j);
		}
	}
}

bool is_random(long long m, long long k, vector<int> &primes){
	if(m <= k || has_4_consec_digits(m)){
		return false;
	}
	for(unsigned i = 0; i < primes.size(); ++i){
		int p = primes[i];
		if(m % p == 0){
			return false;
		}
		if(p * p > m){
			break;
		}
	}
	return true;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long k;
	cin >> n >> k;
	vector<int> primes;
	generate_primes(min(k, (1 << 16) + 1LL), primes);
	for(int i = 0; i < n; ++i){
		long long m;
		cin >> m;
		cout << (is_random(m, k, primes) ? "YES" : "NO") << "\n";
	}
	return 0;
}
