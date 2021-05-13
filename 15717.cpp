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
	long long n;
	cin >> n;
	if(n > 0){
		cout << power(2, n - 1);
	}else{
		cout << 1;
	}
	return 0;
}
