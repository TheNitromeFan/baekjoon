#include <iostream>
#include <cstring>
#include <string>
#define MOD (2 * 3 * 5 * 7)

using namespace std;

long long dp[41][MOD]; // dp[i][x]: # of ways to reach x mod 210 with first i numbers

int main(){
	int n;
	cin >> n;
	for(int p = 1; p <= n; ++p){
		string s;
		cin >> s;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int i = 0; i < s.size(); ++i){
			for(int sgn = (i == 0) ? 1 : -1; sgn <= 1; sgn += 2){
				int cur = 0;
				for(int j = i; j < s.size(); ++j){
					cur *= 10;
					cur += s[j] - '0';
					cur %= MOD;
					for(int x = 0; x < MOD; ++x){
						dp[j+1][(x + sgn * cur + MOD) % MOD] += dp[i][x];
					}
				}
			}
		}
		long long ret = 0;
		for(int x = 0; x < MOD; ++x){
			if(x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0){
				ret += dp[s.size()][x];
			}
		}
		cout << "Case #" << p << ": " << ret << '\n';
	}
	return 0;
}
