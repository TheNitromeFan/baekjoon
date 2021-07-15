#include <iostream>
#include <cstring>
#define MAX 14

using namespace std;

long long cache[MAX * MAX][1 << MAX];

long long dp(int n, int m, int k, int bitmask){
	if(k == n * m && !bitmask){
		return 1;
	}else if(k >= n * m){
		return 0;
	}
	if(cache[k][bitmask] != -1){
		return cache[k][bitmask];
	}
	cache[k][bitmask] = 0;
	if(bitmask & 1){
		cache[k][bitmask] = dp(n, m, k + 1, bitmask >> 1);
	}else{
		cache[k][bitmask] = dp(n, m, k + 1, (bitmask >> 1) | (1 << (m - 1)));
		if(k % m != m - 1 && (bitmask & 2) == 0){
			cache[k][bitmask] += dp(n, m, k + 2, bitmask >> 2);
		}
	}
	return cache[k][bitmask];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		memset(cache, -1, sizeof(cache));
		cout << dp(n, m, 0, 0) << '\n';
	}
	return 0;
}
