#include <iostream>
#include <string>
#define MOD 100003


using std::cin;
using std::cout;

long long combinations[501][501];

long long ways[501][501];

void calculate_combinations(int n, int k){
	if(k > n || combinations[n][k]){
		return;
	}
	if(k == 0 || k == n){
		combinations[n][k] = 1;
		return;
	}
	calculate_combinations(n-1, k-1);
	calculate_combinations(n-1, k);
	combinations[n][k] = (combinations[n-1][k-1] + combinations[n-1][k]) % MOD;
}

void calculate_ways(int n, int k){
	if(k >= n || ways[n][k]){
		return;
	}
	if(k == 1 || k == 2){
		ways[n][k] = 1;
		return;
	}
	long long ret = 0;
	for(int i = 1; i <= k-1; ++i){
		calculate_ways(k, i);
		calculate_combinations(n-k-1, k-i-1);
		ret = (ret + ways[k][i] * combinations[n-k-1][k-i-1] % MOD) % MOD; 
	}
	ways[n][k] = ret;
}

int main(){
	combinations[0][0] = 1;
	ways[2][1] = 1;
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		int n;
		cin >> n;
		long long ans = 0;
		for(int k = 1; k <= n-1; ++k){
			calculate_ways(n, k);
			ans = (ans + ways[n][k]) % MOD; 
		}
		cout << "Case #" << i << ": " << ans << "\n";
	}
	return 0;
}
