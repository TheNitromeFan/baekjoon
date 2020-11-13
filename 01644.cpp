#include <cstdio>
#include <vector>
#define MAX 4000000

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

int ways(int s){
	int ret = 0;
	for(int i = 0; i < primes.size() && primes[i] <= s; ++i){
		int sum = 0;
		for(int j = i; j < primes.size() && sum < s; ++j){
			sum += primes[j];
			if(sum == s){
				++ret;
			}
		}
	}
	return ret;
}

int main(){
	sieve();
	int n;
	scanf("%d", &n);
	printf("%d", ways(n));
	return 0;
}
