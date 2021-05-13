#include <iostream>
#include <vector>

using namespace std;

void prime_factorize(vector<long long> &res, long long n){
	for(long long p = 2; p * p <= n; ++p){
		while(n % p == 0){
			res.push_back(p);
			n /= p;
		}
	}
	if(n > 1){
		res.push_back(n);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	vector<long long> prime_factors;
	prime_factorize(prime_factors, n);
	if(prime_factors.size() <= 1){
		cout << -1;
		return 0;
	}
	unsigned idx = 0;
	for(; idx + 3 < prime_factors.size(); idx += 2){
		cout << prime_factors[idx] * prime_factors[idx + 1] << ' ';
	}
	if(prime_factors.size() % 2 == 0){
		cout << prime_factors[idx] * prime_factors[idx + 1];
	}else{
		cout << prime_factors[idx] * prime_factors[idx + 1] * prime_factors[idx + 2];
	}
	return 0;
}
