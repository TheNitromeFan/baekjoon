#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

long long a[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a%b);
	}
}

long long multiply(long long x, long long y, long long mod){
	return (long long)((__int128)x * y % mod);
}

long long power(long long base, long long exponent, long long mod){
	base %= mod;
	long long result = 1;
	while(exponent > 0){
		if(exponent % 2 == 1){
			result = multiply(result, base, mod);
		}
		base = multiply(base, base, mod);
		exponent /= 2;
	}
	return result;
}


bool miller_rabin(long long n, long long b){ // true for probable prime, false for composite
	if(n % b == 0){
		return false;
	}
	long long d = n-1;
	while(d % 2 == 0){
		if(power(b, d, n) == n-1){
			return true;
		}
		d /= 2;
	}
	long long tmp = power(b, d, n);
	return tmp == n-1 || tmp == 1;
}

bool is_prime(long long n){
	for(int i = 0; i < 12; ++i){
		if(n == a[i]){
			return true;
		}else if(n > 40 && !miller_rabin(n, a[i])){
			return false;
		}
	}
	return n > 40;
}

long long pollard_rho(long long n){
	long long x = rand() % (n-2) + 2;
	long long y = x;
	long long c = rand() % (n-1) + 1;
	while(true){
		x = (multiply(x, x, n) + c) % n;
		y = (multiply(y, y, n) + c) % n;
		y = (multiply(y, y, n) + c) % n;
		long long d = gcd(abs(x-y), n);
		if(d == 1){
			continue;
		}
		if(is_prime(d)){
			return pollard_rho(d);
		}else{
			return d;
		}
	}
}

void get_factors(long long n, vector<long long> &f){
	while(n % 2 == 0){
		n /= 2;
		f.push_back(2);
	}
	if(n == 1){
		return;
	}
	while(!is_prime(n)){
		long long d = pollard_rho(n);
		while(n % d == 0){
			f.push_back(d);
			n /= d;
		}
		if(n == 1){
			break;
		}
	}
	if(n > 1){
		f.push_back(n);
	}
}

int main(){
	long long n;
	scanf("%lld", &n);
	if(n == 1){
		return 0;
	}
	vector<long long> f;
	get_factors(n, f);
	sort(f.begin(), f.end());
	for(long long factor : f){
		printf("%lld\n", factor);
	}
	return 0;
}
