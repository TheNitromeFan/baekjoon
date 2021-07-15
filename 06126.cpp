#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

long long cache[10001][26];

long long dp(vector<int> &coins, int v, int max_idx){
	if(v == 0){
		return 1;
	}
	if(cache[v][max_idx] != -1){
		return cache[v][max_idx];
	}
	cache[v][max_idx] = 0;
	for(int i = 0; i <= max_idx; ++i){
		if(v >= coins[i]){
			cache[v][max_idx] += dp(coins, v - coins[i], i);
		}
	}
	return cache[v][max_idx];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v, n;
	cin >> v >> n;
	vector<int> coins(v);
	for(int i = 0; i < v; ++i){
		cin >> coins[i];
	}
	sort(coins.begin(), coins.end());
	memset(cache, -1, sizeof(cache));
	cout << dp(coins, n, v - 1) << '\n';
	return 0;
}
