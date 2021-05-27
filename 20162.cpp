#include <iostream>
#define MAX 1001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int party[MAX] = {};
	for(int i = 1; i <= n; ++i){
		cin >> party[i];
	}
	int dp[MAX] = {};
	dp[1] = party[1];
	int ans = dp[1];
	for(int i = 2; i <= n; ++i){
		dp[i] = party[i];
		for(int j = 1; j < i; ++j){
			if(party[j] < party[i] && dp[j] + party[i] > dp[i]){
				dp[i] = dp[j] + party[i];
			}
		}
		if(ans < dp[i]){
			ans = dp[i];
		}
	}
	cout << ans;
	return 0;
}
