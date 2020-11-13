#include <iostream>
#include <cstring>

using namespace std;

int dp[1001][31][2];
int tree[1001];

int max(int a, int b){
	return (a > b) ? a : b;
}

int solve(int t, int w, int time, int steps, int current_tree){
	int apple = (tree[time] == current_tree) ? 1 : 0;
	if(time > t || steps > w){
		return 0;
	}
	if(dp[time][steps][current_tree] != -1){
		return dp[time][steps][current_tree];
	}
	dp[time][steps][current_tree] = max(solve(t, w, time+1, steps, current_tree), solve(t, w, time+1, steps+1, !current_tree)) + apple;
	return dp[time][steps][current_tree];
}

int main(){
	int t, w;
	cin >> t >> w;
	for(int i = 1; i <= t; ++i){
		cin >> tree[i];
		--tree[i];
	}
	memset(dp, -1, sizeof(dp));
	tree[0] = 1;
	cout << solve(t, w, 0, 0, 0);
	return 0;
}
