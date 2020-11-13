#include <iostream>

using namespace std;

int mod = 1000000007;

long long factorial(long long x){
	if(x == 0){
		return 1LL;
	}else{
		return x * factorial(x-1) % mod;
	}
}

long long power(long long base, int exponent){
	long long result = 1LL;
	while(exponent > 0){
		if(exponent % 2 == 1){
			result = result * base % mod;
		}
		base = (base * base) % mod;
		exponent /= 2;
	}
	return result;
}

int main(){
	long long n, k;
	cin >> n >> k;
	long long a = factorial(n), b = factorial(k), c = factorial(n-k);
	cout << (a * power(b, mod-2)) % mod * power(c, mod-2) % mod << endl;
	return 0;
}
