#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> all47;
	queue<int> q;
	q.push(4);
	q.push(7);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		all47.push_back(u);
		if(10 * u + 4 <= MAX){
			q.push(10 * u + 4);
		}
		if(10 * u + 7 <= MAX){
			q.push(10 * u + 7);
		}
	}
	int n;
	cin >> n;
	int dp[MAX + 1], prev[MAX + 1];
	memset(dp, -1, sizeof(dp));
	memset(prev, -1, sizeof(prev));
	dp[0] = 0;
	for(int i = 4; i <= n; ++i){
		for(int x : all47){
			if(x > i){
				break;
			}
			if(dp[i - x] != -1 && (dp[i] == -1 || dp[i] > dp[i - x] + 1)){
				dp[i] = dp[i - x] + 1;
				prev[i] = i - x;
			}
		}
	}
	if(dp[n] == -1){
		cout << -1;
		return 0;
	}
	vector<int> ans;
	while(n > 0){
		ans.push_back(n - prev[n]);
		n = prev[n];
	}
	sort(ans.begin(), ans.end());
	for(int x : ans){
		cout << x << ' ';
	}
	return 0;
}
