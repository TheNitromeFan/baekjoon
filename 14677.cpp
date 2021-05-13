#include <iostream>
#include <string>
#define MAX 1510

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n;
	cin >> n;
	string s;
	cin >> s;
	string bld = "BLD";
	bool dp[MAX][MAX] = {};
	dp[0][0] = true;
	unsigned ans = 0;
	for(unsigned i = 1; i <= 3 * n; ++i){
		for(unsigned j = 0; j <= i; ++j){
			unsigned k = i - j;
			if((j >= 1 && dp[j - 1][k] && s[j - 1] == bld[(i - 1) % 3])
			|| (k >= 1 && dp[j][k - 1] && s[3 * n - k] == bld[(i - 1) % 3])){
				dp[j][k] = true;
				ans = i;
			}
		}
	}
	cout << ans;
	return 0;
}
