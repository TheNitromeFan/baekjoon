#include <iostream>
#define MOD 1000000007

using namespace std;

long long power(long long base, long long exp){
	if(exp == 0){
		return 1;
	}else if(exp % 2 == 0){
		return power(base * base % MOD, exp / 2);
	}else{
		return power(base * base % MOD, exp / 2) * base % MOD;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		long long k;
		cin >> k;
		ans += power(2, k);
		ans %= MOD;
	}
	cout << ans;
	return 0;
}
