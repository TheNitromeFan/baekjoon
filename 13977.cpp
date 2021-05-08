#include <iostream>
#define MOD 1000000007
#define MAX 4000001

using namespace std;

long long pow(long long base, long long exp){
	if(exp == 0){
		return 1;
	}else if(exp % 2 == 0){
		return pow(base * base % MOD, exp / 2);
	}else{
		return base * pow(base * base % MOD, exp / 2) % MOD;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long fact[MAX] = {}, invfact[MAX] = {};
	fact[0] = 1;
	invfact[0] = 1;
	for(long long i = 1; i < MAX; ++i){
		fact[i] = fact[i - 1] * i % MOD;
		invfact[i] = invfact[i - 1] * pow(i, MOD - 2) % MOD;
	}
	int m;
	cin >> m;
	for(int a0 = 0; a0 < m; ++a0){
		int n, k;
		cin >> n >> k;
		cout << ((fact[n] * invfact[k] % MOD) * invfact[n - k] % MOD) << '\n';
	}
	return 0;
}
