#include <iostream>

using namespace std;

bool prime_power(long long n){
	if(n == 1){
		return false;
	}
	for(long long p = 2; p * p <= n; ++p){
		if(n % p == 0){
			long long pn = p;
			while(pn < n){
				pn *= p;
			}
			return pn == n;
		}
	}
	return true;
}

int main(){
	long long q;
	cin >> q;
	cout << (prime_power(q) ? "yes" : "no");
	return 0;
}
