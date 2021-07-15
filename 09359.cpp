#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void get_prime_factors(vector<int> &primes, int n){
	for(int p = 2; p * p <= n; ++p){
		int cnt = 0;
		while(n % p == 0){
			++cnt;
			n /= p;
		}
		if(cnt > 0){
			primes.push_back(p);
		}
	}
	if(n > 1){
		primes.push_back(n);
	}
}

long long coprime(vector<int> &primes, long long m){
	long long ret = 0;
	int sign = 1;
	for(vector<int>::size_type len = 0; len <= primes.size(); ++len){
		vector<int> bitmask(len, 1);
		bitmask.resize(primes.size());
		do{
			int prod = 1;
			for(unsigned i = 0; i < primes.size(); ++i){
				if(bitmask[i]){
					prod *= primes[i];
				}
			}
			ret += sign * m / prod;
		}while(prev_permutation(bitmask.begin(), bitmask.end()));
		sign *= -1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		long long a, b;
		int n;
		cin >> a >> b >> n;
		vector<int> primes;
		get_prime_factors(primes, n);
		cout << "Case #" << i << ": " << coprime(primes, b) - coprime(primes, a - 1) << "\n";
	}
	return 0;
}
