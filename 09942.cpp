#include <iostream>
#include <cmath>
#define MAX 1001

using namespace std;

int p(int n){
	return (int)(sqrt(1 + 8 * n) - 1) / 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long dp[MAX] = {};
	for(int i = 1; i < MAX; ++i){
		dp[i] = dp[i - 1] + (1LL << p(i - 1));
	}
	int t = 0;
	int n;
	while(cin >> n){
		++t;
		cout << "Case " << t << ": " << dp[n] << "\n";
	}
	return 0;
}
