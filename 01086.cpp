#include <iostream>
#include <string>
#include <cstring>

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

long long conc(long long dp[][111], int powers[55], int arr[20], unsigned len[20], int n, int k, int bit, int md){
	if(dp[bit][md] != -1){
		return dp[bit][md];
	}
	dp[bit][md] = 0;
	if(bit + 1 == (1 << n)){
		if(md == 0){
			dp[bit][md] = 1;
		}
		return dp[bit][md];
	}
	for(int i = 0; i < n; ++i){
		if(!(bit & (1 << i))){
			dp[bit][md] += conc(dp, powers, arr, len, n, k, bit | (1 << i), (md * powers[len[i]] + arr[i]) % k);
		}
	}
	return dp[bit][md];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s[20];
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	int k;
	cin >> k;
	unsigned len[20];
	int arr[20];
	for(int i = 0; i < n; ++i){
		len[i] = s[i].length();
		arr[i] = 0;
		for(char c : s[i]){
			arr[i] = arr[i] * 10 + c - '0';
			arr[i] %= k;
		}
	}
	long long dp[1 << 15][111];
	memset(dp, -1, sizeof(dp));
	int powers[55];
	powers[0] = 1 % k;
	for(int i = 1; i < 55; ++i){
		powers[i] = powers[i - 1] * 10 % k;
	}
	long long p = conc(dp, powers, arr, len, n, k, 0, 0), q = 1;
	if(p == 0){
		cout << "0/1";
		return 0;
	}
	for(int i = 1; i <= n; ++i){
		q *= i;
	}
	long long g = gcd(p, q);
	cout << p / g << "/" << q / g;
	return 0;
}
