#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

long long common_prime_factor(long long a, long long b){
	if(a != b){
		return gcd(a, b);
	}
	if(a > b){
		swap(a, b);
	}
	if(a % 2 == 0){
		return 2;
	}
	for(long long p = 3; p * p <= a; p += 2){
		if(a % p == 0){
			return p;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long c1, c2, c3, c4, c5, c6;
	cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
	long long x2 = common_prime_factor(c1, c5);
	long long x1 = c1 / x2, x3 = c5 / x2;
	long long x6 = common_prime_factor(c3, c6);
	long long x5 = c6 / x6, x7 = c3 / x6;
	cout << x1 << ' ' << x2 << ' ' << x3 << ' ' << x5 << ' ' << x6 << ' ' << x7 << '\n';
	return 0;
}
