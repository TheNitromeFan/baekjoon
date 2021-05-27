#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define MAX 301

using namespace std;

int dp[MAX][MAX];

int dist(string &a, string &b, int n, int m, int i, int j){
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	dp[i][j] = 1000000000;
	if(i < n - 1 && j < m - 1){
		dp[i][j] = min(dp[i][j], dist(a, b, n, m, i + 1, j + 1));
	}
	if(i < n - 1){
		dp[i][j] = min(dp[i][j], dist(a, b, n, m, i + 1, j));
	}
	if(j < m - 1){
		dp[i][j] = min(dp[i][j], dist(a, b, n, m, i, j + 1));
	}
	dp[i][j] += abs(a[i] - b[j]);
	return dp[i][j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	memset(dp, -1, sizeof(dp));
	dp[n - 1][m - 1] = abs(a[n - 1] - b[m - 1]);
	cout << dist(a, b, n, m, 0, 0);
	return 0;
}
