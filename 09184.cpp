#include <iostream>
#include <cstring>

using namespace std;

long long w(long long dp[][21][21], int a, int b, int c){
	if(a <= 0 || b <= 0 || c <= 0){
		return 1;
	}else if(a > 20 || b > 20 || c > 20){
		return w(dp, 20, 20, 20);
	}
	if(dp[a][b][c] != -1){
		return dp[a][b][c];
	}
	if(a < b && b < c){
		dp[a][b][c] = w(dp, a, b, c - 1) + w(dp, a, b - 1, c - 1) - w(dp, a, b - 1, c);
	}else{
		dp[a][b][c] = w(dp, a - 1, b, c) + w(dp, a - 1, b - 1, c) + w(dp, a - 1, b, c - 1) - w(dp, a - 1, b - 1, c - 1);
	}
	return dp[a][b][c];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long dp[21][21][21];
	memset(dp, -1, sizeof(dp));
	while(true){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1){
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(dp, a, b, c) << "\n";
	}
	return 0;
}
