#include <iostream>
#define MAX 10000001

using namespace std;

static bool is_not_prime[MAX];

void sieve(int upper_bound){
	is_not_prime[0] = true;
	is_not_prime[1] = true;
	for(long long i = 2; i <= upper_bound; ++i){
		if(is_not_prime[i]){
			continue;
		}
		for(long long m = i; i * m <= upper_bound; ++m){
			is_not_prime[i * m] = true;
		}
	}
}

int main(){
	sieve(MAX-1);
	long long a, b;
	cin >> a >> b;
	int ans = 0;
	for(long long p = 2; p * p <= b; ++p){
		if(is_not_prime[p]){
			continue;
		}
		long long power = p;
		while(power <= b / p){
			if(power * p >= a){
				++ans;
			}
			power *= p;
		}
	}
	cout << ans;
	return 0;
}
