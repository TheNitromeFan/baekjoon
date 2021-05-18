#include <iostream>
#include <vector>
#include <algorithm>

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

int nu(long long n, int p){
	int ret = 0;
	while(n % p == 0){
		n /= p;
		++ret;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> primes;
	erathosthenes_sieve(primes, 1000000);
	int a, b;
	long long lcm;
	cin >> a >> b >> lcm;
	long long c = 1;
	for(int p : primes){
		int e1 = nu(a, p), e2 = nu(b, p), e3 = nu(lcm, p);
		int e0 = max(e1, e2);
		if(e0 > e3){
			cout << -1;
			return 0;
		}else if(e0 < e3){
			for(int a0 = 0; a0 < e3; ++a0){
				c *= p;
			}
		}
		for(int a0 = 0; a0 < e3; ++a0){
			lcm /= p;
		}
	}
	if(lcm > 1){
		c *= lcm;
	}
	cout << c;
	return 0;
}
