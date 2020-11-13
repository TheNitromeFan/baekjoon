#include <iostream>
#include <string>
#define MAX (1000 + 1)
#define MOD 10007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	static int dp[MAX] = {}, psum[MAX] = {};
	for(unsigned i = 1; i <= s.length(); ++i){
		for(unsigned j = i; j <= s.length(); ++j){
			if(s[i - 1] == s[j - 1]){
				dp[j] = (dp[j] + psum[s.length()] - psum[j] + 1 + MOD) % MOD;
			}
			psum[j] = (psum[j - 1] + dp[j]) % MOD;
		}
	}
	cout << psum[s.length()];
	return 0;
}
