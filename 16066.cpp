#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

bool prime(long long n){
	if(n == 1){
		return false;
	}
	for(long long p = 2; p * p <= n; ++p){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		long double a, b;
		cin >> a >> b;
		long long x = (long long)(a * 100000), y = (long long)(b * 100000);
		long long g = gcd(x, y);
		x /= g;
		y /= g;
		if(x == 1 && y == 1){
			x = 2;
			y = 2;
		}
		if(prime(x) && prime(y)){
			cout << x << ' ' << y << '\n';
		}else{
			cout << "impossible\n";
		}
	}
	return 0;
}
