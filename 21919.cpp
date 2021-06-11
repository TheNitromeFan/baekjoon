#include <iostream>
#include <vector>
#include <unordered_set>
#define MAX 1000000

using namespace std;

void sieve(unordered_set<int> &primes, int limit){
	vector<bool> is_prime(limit + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 4; i <= limit; i += 2){
		is_prime[i] = false;
	}
	for(int p = 3; p * p <= limit; p += 2){
		for(int i = p * p; i <= limit; i += 2 * p){
			is_prime[i] = false;
		}
	}
	for(int i = 0; i <= limit; ++i){
		if(is_prime[i]){
			primes.insert(i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<int> primes;
	sieve(primes, MAX);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	long long ans = 1;
	for(int i = 0; i < n; ++i){
		if(primes.find(a[i]) != primes.end() && ans % a[i] != 0){
			ans *= a[i];
		}
	}
	cout << (ans > 1 ? ans : -1);
	return 0;
}
