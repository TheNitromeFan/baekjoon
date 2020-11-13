#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 1000

using namespace std;

vector<int> generate_primes(){
	vector<bool> prime(MAX + 1, true);
	prime[0] = false;
	prime[1] = false;
	for(int p = 2; p * p <= MAX; ++p){
		if(!prime[p]){
			continue;
		}
		for(int m = p; m * p <= MAX; ++m){
			prime[m * p] = false;
		}
	}
	vector<int> ret;
	for(int i = 0; i <= MAX; ++i){
		if(prime[i]){
			ret.push_back(i);
		}
	}
	return ret;
}

void print_3_primes(vector<int> &primes, int n){
	for(int i = 0; i < primes.size(); ++i){
		for(int j = 0; j <= i; ++j){
			for(int k = 0; k <= j; ++k){
				if(primes[i] + primes[j] + primes[k] == n){
					printf("%d %d %d\n", primes[k], primes[j], primes[i]);
					return;
				}
			}
		}
	}
	printf("0\n");
}

int main(){
	vector<int> primes = generate_primes();
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		print_3_primes(primes, n);
	}
	return 0;
}
