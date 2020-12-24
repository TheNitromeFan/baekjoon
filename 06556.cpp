#include <iostream>
#include <cstring>

using namespace std;

long long dp[1000][1000];

long long comb(long long n, long long k){
	if(k == 0 || k == n){
		return 1;
	}else if(k == 1 || k == n - 1){
		return n;
	}else if(k == 2 || k == n - 2){
		if(n % 2 == 0){
			return n / 2 * (n - 1);
		}else{
			return (n - 1) / 2 * n;
		}
	}else if(k == 3 || k == n - 3){
		if(n % 6 == 0){
			return n / 6 * (n - 1) * (n - 2);
		}else if(n % 6 == 1){
			return (n - 1) / 6 * n * (n - 2);
		}else if(n % 6 == 2){
			return (n - 2) / 6 * n * (n - 1);
		}else if(n % 6 == 3){
			return n / 3 * ((n - 1) / 2) * (n - 2);
		}else if(n % 6 == 4){
			return n / 2 * ((n - 1) / 3) * (n - 2);
		}else{
			return (n - 1) / 2 * ((n - 2) / 3) * n;
		}
	}
	if(dp[n][k] != -1){
		return dp[n][k];
	}
	dp[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);
	return dp[n][k];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	while(true){
		long long n, m;
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		cout << comb(n + m, n) << '\n';
	}
	return 0;
}
