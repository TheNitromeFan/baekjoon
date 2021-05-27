#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX (1 << 20)

using namespace std;

int cache[MAX];

int dp(int a[][20], int n, int bitmask, int idx){
	if(idx == n){
		return 0;
	}
	if(cache[bitmask] != -1){
		return cache[bitmask];
	}
	cache[bitmask] = 100000000;
	for(int i = 0; i < n; ++i){
		if(!(bitmask & (1 << i))){
			cache[bitmask] = min(cache[bitmask], a[idx][i] + dp(a, n, bitmask | (1 << i), idx + 1));
		}
	}
	return cache[bitmask];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[20][20];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	int ans = 1000000000;
	for(int i = 0; i < n; ++i){
		ans = min(ans, a[0][i] + dp(a, n, 1 << i, 1));
	}
	cout << ans;
	return 0;
}
