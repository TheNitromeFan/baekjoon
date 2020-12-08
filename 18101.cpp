#include <iostream>

using namespace std;

long long divisor(long long n){
	for(long long d = 3; d * d <= n; ++d){
		if(n % d == 0){
			return d;
		}
	}
	if(n % 2 == 0 && n >= 6){
		return n / 2;
	}
	return n;
}

int main(){
	long long n;
	cin >> n;
	cout << divisor(n);
	return 0;
}
