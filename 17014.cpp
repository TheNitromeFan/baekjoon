#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void erathosthenes(unordered_set<int> &primes, int n){
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 4; i <= n; i += 2){
		is_prime[i] = false;
	}
	for(int p = 3; p * p <= n; p += 2){
		for(int i = 2 * p; i <= n; i += p){
			is_prime[i] = false;
		}
	}
	for(int i = 0; i <= n; ++i){
		if(is_prime[i]){
			primes.insert(i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	unordered_set<int> primes;
	erathosthenes(primes, 2000000);
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		n *= 2;
		for(int p = 2; 2 * p <= n; ++p){
			if(primes.find(p) != primes.end() && primes.find(n - p) != primes.end()){
				cout << p << ' ' << n - p << '\n';
				break;
			}
		}
	}
	return 0;
}
