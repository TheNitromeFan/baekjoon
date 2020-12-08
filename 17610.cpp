#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAXN (13 + 1)
#define MAXW (13 * 200000 + 1)

using namespace std;

void weigh(bool dp[MAXN][MAXW], int weights[MAXN], int n, int w, int sum, int &s){
	if(w > n){
		return;
	}
	if(dp[w][sum]){
		return;
	}
	if(w == n && !dp[w][sum]){
		--s;
	}
	dp[w][sum] = true;
	weigh(dp, weights, n, w + 1, sum, s);
	weigh(dp, weights, n, w + 1, sum + weights[w], s);
	weigh(dp, weights, n, w + 1, abs(sum - weights[w]), s);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int weights[MAXN];
	int s = 1;
	for(int i = 0; i < n; ++i){
		cin >> weights[i];
		s += weights[i];
	}
	bool dp[MAXN][MAXW] = {};
	weigh(dp, weights, n, 0, 0, s);
	cout << s;
	return 0;
}
