#include <iostream>
#include <deque>
#include <algorithm>
#define MAX 100000
#define MAXVAL 1000000000000000000LL

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d;
	cin >> n >> d;
	int k[MAX];
	for(int i = 0; i < n; ++i){
		cin >> k[i];
	}
	long long dp[MAX], ans = -MAXVAL;
	fill(dp, dp + n, -MAXVAL);
	deque<int> dq;
	for(int i = 0; i < n; ++i){
		while(!dq.empty() && dq.front() < i - d){
			dq.pop_front();
		}
		if(!dq.empty() && dp[dq.front()] >= 0){
			dp[i] = dp[dq.front()] + k[i];
		}else{
			dp[i] = k[i];
		}
		ans = max(ans, dp[i]);
		// cout << ans << '\n';
		while(!dq.empty() && dp[dq.back()] <= dp[i]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	cout << ans;
	return 0;
}
