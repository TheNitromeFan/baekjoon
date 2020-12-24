#include <iostream>
#include <vector>
#define MAX 5000000

using namespace std;

void sieve(vector<int> &primes, int limit){
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
			primes.push_back(j);
		}
	}
}

void factorize(vector<int> &v, int n){
	for(int i = 0; v[i] * v[i] <= n; ++i){
		int p = v[i];
		while(n % p == 0){
			cout << p << ' ';
			n /= p;
		}
	}
	if(n > 1){
		cout << n;
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> primes;
	sieve(primes, MAX);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		factorize(primes, k);
	}
	return 0;
}
