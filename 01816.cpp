#include <cstdio>
#include <vector>
#define MAX 1000000

bool is_not_prime[MAX+1];

std::vector<int> primes;

void sieve(){
	is_not_prime[0] = true;
	is_not_prime[1] = true;
	for(int m = 2; m * 2 <= MAX; ++m){
		is_not_prime[m * 2] = true;
	}
	for(int p = 3; p * p <= MAX; p += 2){
		for(int m = p; m * p <= MAX; m += 2){
			is_not_prime[m * p] = true;
		}
	}
	for(int i = 2; i <= MAX; ++i){
		if(!is_not_prime[i]){
			primes.push_back(i);
		}
	}
}

bool pseudoprime(long long s){
	for(int p : primes){
		if(s % p == 0){
			return false;
		}
	}
	return true;
}

int main(){
	sieve();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		long long x;
		scanf("%lld", &x);
		if(pseudoprime(x)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
