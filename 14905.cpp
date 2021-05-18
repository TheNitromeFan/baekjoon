#include <iostream>
#include <vector>

using namespace std;

void erathosthenes_sieve(vector<int> &primes, int n){
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
			primes.push_back(i);
		}
	}
}

bool prime(vector<int> &primes, int n){
	if(n <= 1){
		return false;
	}
	for(int p : primes){
		if(p * p > n){
			break;
		}
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

void sum_of_4_primes(vector<int> &primes, int n){
	for(int p1 : primes){
		for(int p2 : primes){
			for(int p3 : primes){
				if(p1 + p2 + p3 + 1 >= n){
					break;
				}
				if(prime(primes, n - p1 - p2 - p3)){
					cout << p1 << ' ' << p2 << ' ' << p3 << ' ' << n - p1 - p2 - p3 << '\n';
					return;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> primes;
	erathosthenes_sieve(primes, 40000);
	int n;
	while(cin >> n){
		if(n <= 7){
			cout << "Impossible.\n";
			continue;
		}
		sum_of_4_primes(primes, n);
	}
	return 0;
}
