#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 50
#define MAXVAL 250000
#define INF 1000000000

using namespace std;

int dp[MAX][MAXVAL + 5];

int max_height(int a[MAX], int n, int idx, int d){
	if(d > MAXVAL || (idx == n && d != 0)){
		return -INF;
	}else if(idx == n && d == 0){
		return 0;
	}
	if(dp[idx][d] != -1){
		return dp[idx][d];
	}
	dp[idx][d] = -INF;
	dp[idx][d] = max(dp[idx][d], max_height(a, n, idx + 1, d));
	dp[idx][d] = max(dp[idx][d], max_height(a, n, idx + 1, d + a[idx]));
	if(a[idx] > d){
		dp[idx][d] = max(dp[idx][d], d + max_height(a, n, idx + 1, a[idx] - d));
	}else{
		dp[idx][d] = max(dp[idx][d], a[idx] + max_height(a, n, idx + 1, d - a[idx]));
	}
	return dp[idx][d];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	int ans = max_height(a, n, 0, 0);
	cout << (ans ? ans : -1);
	return 0;
}
