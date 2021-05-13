#include <iostream>
#define MOD 1000000007

using namespace std;

long long power(long long base, long long exp){
	if(exp == 0){
		return 1;
	}else if(exp % 2 == 0){
		return power(base * base % MOD, exp / 2);
	}else{
		return base * power(base * base % MOD, exp / 2) % MOD;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, n;
	cin >> a >> b >> n;
	cout << power((1LL << 31) % MOD, n - 1);
	return 0;
}
