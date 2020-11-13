#include <cstdio>
#include <vector>

using namespace std;

vector<int> prime_divisors(int n){
	vector<int> ret;
	for(int p = 2; p * p <= n; ++p){
		if(n % p == 0){
			ret.push_back(p);
			while(n % p == 0){
				n /= p;
			}
		}
	}
	if(n > 1){
		ret.push_back(n);
	}
	return ret;
}

int phi(int n){
	vector<int> primes = prime_divisors(n);
	int ret = n;
	for(int prime : primes){
		ret /= prime;
		ret *= (prime - 1);
	}
	return ret;
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		printf("%d\n", phi(n));
	}
	return 0;
}
