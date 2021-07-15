#include <iostream>
#include <algorithm>
#define MAXH 5001
#define MAXC 50001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, h;
	cin >> c >> h;
	int a[MAXH];
	for(int j = 0; j < h; ++j){
		cin >> a[j];
	}
	int dp[MAXC] = {};
	for(int j = 0; j < h; ++j){
		for(int i = c; i >= 0; --i){
			if(i >= a[j]){
				dp[i] = max(dp[i], dp[i - a[j]] + a[j]);
			}
		}
	}
	cout << dp[c] << '\n';
	return 0;
}
