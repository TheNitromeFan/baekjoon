#include <iostream>
#define MOD 998244353

using namespace std;

long long power(long long a, long long b){
	long long ret = 1;
	while(b){
		if(b % 2 == 1){
			ret = ret * a % MOD;
		}
		b /= 2;
		a = a * a % MOD;
	}
	return ret;
}

long long solve(int n, int m){
	long long fac[1010101] = {};
	fac[0] = 1;
	for(int i = 1; i < 1010101; ++i){
		fac[i] = fac[i - 1] * i % MOD;
	}
	long long left[303030] = {}, right[303030] = {};
	for(int j = 1; j < 303030; ++j){
		left[j] = min(min(-left[j - 1], -left[j - 1] - 1), min(-right[j - 1], -right[j - 1] - 1));
		right[j] = max(max(-left[j - 1], -left[j - 1] - 1), max(-right[j - 1], -right[j - 1] - 1));
	}
	if(m < left[n] || m > right[n]){
		return 0;
	}
	m -= left[n];
	return fac[n] * power(fac[m], MOD - 2) % MOD * power(fac[n - m], MOD - 2) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	cout << solve(n, m);
	return 0;
}
