#include <iostream>
#include <string>

using namespace std;

char xyz(long long dp[101], int n, long long k){
	if(n == 1){
		return 'X';
	}else if(n == 2){
		if(k == 1){
			return 'Y';
		}else{
			return 'Z';
		}
	}else if(n == 3){
		if(k == 1){
			return 'Z';
		}else{
			return 'X';
		}
	}
	if(k <= dp[n - 3]){
		return xyz(dp, n - 3, k);
	}else{
		return xyz(dp, n - 2, k - dp[n - 3]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int problem, n;
	cin >> problem >> n;
	long long dp[101] = {};
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	for(int i = 4; i <= 100; ++i){
		dp[i] = dp[i - 3] + dp[i - 2];
	}
	long long x[101] = {}, y[101] = {}, z[101] = {};
	x[1] = 1;
	for(int i = 2; i <= 100; ++i){
		x[i] = z[i - 1];
		y[i] = x[i - 1];
		z[i] = x[i - 1] + y[i - 1];
	}
	if(problem == 1){
		cout << dp[n];
	}else if(problem == 2){
		long long k;
		cin >> k;
		cout << xyz(dp, n, k);
	}else if(problem == 3){
		char c;
		cin >> c;
		if(c == 'X'){
			cout << x[n];
		}else if(c == 'Y'){
			cout << y[n];
		}else if(c == 'Z'){
			cout << z[n];
		}
	}
	return 0;
}
