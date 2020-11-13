#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 40000
#define MOD 123456789

using namespace std;

vector<int> generate_primes(){
	bool is_prime[MAX];
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = false;
	for(int p = 2; p * p < MAX; ++p){
		if(!is_prime[p]){
			continue;
		}
		for(int m = p; m * p < MAX; ++m){
			is_prime[m * p] = false;
		}
	}
	vector<int> ret;
	for(int i = 0; i < MAX; ++i){
		if(is_prime[i]){
			ret.push_back(i);
		}
	}
	return ret;
}

int main(){
	vector<int> primes = generate_primes();
	int n;
	scanf("%d", &n);
	int dp[MAX + 1] = {};
	dp[0] = 1;
	for(unsigned j = 0; j < primes.size(); ++j){
		for(int i = primes[j]; i <= n; ++i){
			dp[i] = (dp[i] + dp[i - primes[j]]) % MOD;
		}
	}
	printf("%d", dp[n]);
	return 0;
}
