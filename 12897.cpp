#include <iostream>
#define MOD 1000000007

using namespace std;

long long power(long long base, int exp, long long mod){
	if(exp == 0){
		return 1;
	}else if(exp % 2 == 0){
		long long x = power(base, exp / 2, mod);
		return x * x % mod;
	}else{
		long long x = power(base, exp / 2, mod);
		return (x * x) % mod * base % mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long three_n = power(3, n, MOD);
	cout << three_n - 1;
	return 0;
}
