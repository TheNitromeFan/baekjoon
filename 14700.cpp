#include <iostream>
#include <cstring>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	if(n < m){
		swap(n, m);
	}
	static int dp[301][1 << 18];
	for(int bit = 0; bit < (1 << m); ++bit){
		dp[0][bit] = 1;
	}
	for(int idx = 1; idx <= n * m; ++idx){
		for(int bit = 0; bit < (1 << m); ++bit){
			dp[idx][bit] = dp[idx - 1][bit >> 1];
			if(idx % m == 0 || !(bit & (1 << m)) || !(bit & 2) || !(bit & 1)){
				dp[idx][bit] += dp[idx - 1][(bit >> 1) | (1 << m)];
			}
			dp[idx][bit] %= MOD;
		}
	}
	cout << dp[n * m][0] << '\n';
	return 0;
}
