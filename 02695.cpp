#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 1001
#define MAXK 51

using namespace std;

int cache[MAXN][MAXK];

int dp(int n, int k){
	if(n == 0 || k == 1){
		return n;
	}
	if(cache[n][k] != -1){
		return cache[n][k];
	}
	cache[n][k] = 1000000000;
	for(int i = 1; i <= n; ++i){
		cache[n][k] = min(cache[n][k], 1 + max(dp(i - 1, k - 1), dp(n - i, k)));
	}
	return cache[n][k];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	memset(cache, -1, sizeof(cache));
	for(int i = 0; i < t; ++i){
		int n, k;
		cin >> k >> n;
		cout << dp(n, k) << '\n';
	}
	return 0;
}
