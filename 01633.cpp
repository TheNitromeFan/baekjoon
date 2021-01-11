#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#define MAX 16
#define MAXPLAYERS 1000

using namespace std;

int dp[MAXPLAYERS][MAX][MAX];

vector<pair<int, int>> players;

int knapsack(unsigned idx, int w, int b){
	if(idx == players.size()){
		return 0;
	}
	if(dp[idx][w][b] != -1){
		return dp[idx][w][b];
	}
	if(w > 0){
		dp[idx][w][b] = max(dp[idx][w][b], knapsack(idx + 1, w - 1, b) + players[idx].first);
	}
	if(b > 0){
		dp[idx][w][b] = max(dp[idx][w][b], knapsack(idx + 1, w, b - 1) + players[idx].second);
	}
	dp[idx][w][b] = max(dp[idx][w][b], knapsack(idx + 1, w, b));
	return dp[idx][w][b];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, b;
	while(cin >> w >> b){
		players.push_back(make_pair(w, b));
	}
	memset(dp, -1, sizeof(dp));
	cout << knapsack(0, 15, 15);
	return 0;
}
