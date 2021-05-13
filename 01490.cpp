#include <iostream>

using namespace std;

bool divisible_by_digits(long long n, long long m){
	while(m > 0){
		long long r = m % 10;
		if(r != 0 && n % r != 0){
			return false;
		}
		m /= 10;
	}
	return true;
}

long long smallest(long long n){
	long long power_of_10 = 1;
	while(true){
		for(long long x = n * power_of_10; x < n * power_of_10 + power_of_10; ++x){
			if(divisible_by_digits(x, n)){
				return x;
			}
		}
		power_of_10 *= 10;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	cout << smallest(n);
	return 0;
}
