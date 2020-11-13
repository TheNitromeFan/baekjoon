#include <iostream>
#include <string>
#include <algorithm>
#define MAX 2500

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	unsigned n = s.length();
	s = " " + s;
	static bool is_palindrome[MAX + 1][MAX + 1];
	for(unsigned i = 1; i <= n; ++i){
		is_palindrome[i][i] = true;
	}
	for(unsigned i = 1; i + 1 <= n; ++i){
		is_palindrome[i][i + 1] = (s[i] == s[i + 1]);
	}
	for(unsigned len = 3; len <= n; ++len){
		for(unsigned i = 1; i + len - 1 <= n; ++i){
			unsigned j = i + len - 1;
			is_palindrome[i][j] = (is_palindrome[i + 1][j - 1] && (s[i] == s[j]));
		}
	}
	int dp[MAX + 1] = {};
	for(int j = 1; j <= n; ++j){
		dp[j] = MAX + 1;
		for(int i = 1; i <= j; ++i){
			if(is_palindrome[i][j] && dp[j] > dp[i - 1] + 1){
				dp[j] = dp[i - 1] + 1;
			}
		}
	}
	cout << dp[n];
	return 0;
}
