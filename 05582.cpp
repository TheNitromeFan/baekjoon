#include <iostream>
#include <string>
#define MAX 4000

using namespace std;

int main(){
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	static int dp[MAX+1][MAX+1] = {};
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(s[i-1] == t[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				if(dp[i][j] > ans){
					ans = dp[i][j];
				}
			}else{
				dp[i][j] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}
