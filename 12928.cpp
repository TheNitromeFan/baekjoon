#include <iostream>
#include <cstring>

using namespace std;

int cache[51][1001];

int dp(int n, int s, int m, int c){
	if(m == n && c == s){
		return 1;
	}else if(m == n || c > s){
		return 0;
	}else if(cache[m][c] != -1){
		return cache[m][c];
	}
	cache[m][c] = 0;
	for(int i = 1; m + i <= n; ++i){
		if(dp(n, s, m + i, c + i * (i + 1) / 2)){
			cache[m][c] = 1;
			break;
		}
	}
	return cache[m][c];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	memset(cache, -1, sizeof(cache));
	cout << dp(n, s, 2, 0) << '\n';
	return 0;
}
