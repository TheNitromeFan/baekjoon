#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[301][1 << 18];

int dp(int n, int m, int idx, int bit){
	if(idx == n * m){
		return 1;
	}
	if(cache[idx][bit] != -1){
		return cache[idx][bit];
	}
	cache[idx][bit] = dp(n, m, idx + 1, bit >> 1);
	if(idx % m == 0){
		cache[idx][bit] += dp(n, m, idx + 1, (bit >> 1) | (1 << m));
	}else if(!(bit & (1 << m)) || !(bit & 2) || !(bit & 1)){
		cache[idx][bit] += dp(n, m, idx + 1, (bit >> 1) | (1 << m));
	}
	return cache[idx][bit];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	if(n < m){
		swap(n, m);
	}
	memset(cache, -1, sizeof(cache));
	cout << dp(n, m, 0, 0) << '\n';
	return 0;
}
