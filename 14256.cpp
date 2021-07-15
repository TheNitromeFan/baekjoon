#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void odd_power_prime_factors(vector<int> &primes, int n){
	for(int p = 2; p * p <= n; ++p){
		int cnt = 0;
		while(n % p == 0){
			n /= p;
			++cnt;
		}
		if(cnt % 2 == 1){
			primes.push_back(p);
		}
	}
	if(n > 1){
		primes.push_back(n);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	long long ans = 0;
	for(int a = 1; a <= n; ++a){
		vector<int> primes;
		odd_power_prime_factors(primes, a);
		int prod = 1;
		for(int p : primes){
			prod *= p;
		}
		ans += (int)sqrt(m / prod);
	}
	cout << ans << '\n';
	return 0;
}
