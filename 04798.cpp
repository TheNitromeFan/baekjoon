#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void erathosthenes_sieve(vector<bool> &is_prime, vector<int> &res, int n){
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 4; i <= n; i += 2){
		is_prime[i] = false;
	}
	for(int p = 3; p * p <= n; p += 2){
		for(int i = 3 * p; i <= n; i += p){
			is_prime[i] = false;
		}
	}
	for(int i = 0; i <= n; ++i){
		if(is_prime[i]){
			res.push_back(i);
		}
	}
}

bool prime(vector<bool> &is_prime, vector<int> &primes, long long n){
	if(n <= 1000000){
		return is_prime[n];
	}
	for(int p : primes){
		if((long long)p * p > n){
			break;
		}
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

void extended_gcd(long long a, long long b, long long &x, long long &y, long long &g){
	long long r, r1, r2, a1, a2, b1, b2, q;
	a1 = b2 = 1;
	a2 = b1 = 0;
	while (b > 0){
		q = a / b;
		r = a % b;
		r1 = a1 - q*b1;
		r2 = a2 - q*b2;
		a = b;
		a1 = b1;
		a2 = b2;
		b = r;
		b1 = r1;
		b2 = r2;
	}
	x = a1;
	y = a2;
	g = a;
}

unsigned dirichlet(vector<bool> &is_prime, vector<int> &primes, long long a, long long b, long long lower, long long upper){
	long long g = 0, x = 0, y = 0;
	extended_gcd(a, b, x, y, g);
	if(g > 1){
		return lower == 0 && prime(is_prime, primes, b);
	}
	vector<bool> nprime(1000002, true);
	long long range = upper - lower + 1;
	if(lower == 0){
		nprime[0] = prime(is_prime, primes, b);
	}
	if(lower <= 1){
		nprime[1 - lower] = prime(is_prime, primes, a + b);
	}
	long long maxval = a * upper + b;
	for(int p : primes){
		if(a % p == 0){
			continue;
		}
		if((long long)p * p > maxval){
			break;
		}
		extended_gcd(a, p, x, y, g);
		long long nstart = (-(b * x)) % p;
		if(nstart < 0){
			nstart += p;
		}
		long long lower_rem = lower % p;
		nstart -= lower_rem;
		if(nstart < 0){
			nstart += p;
		}
		while(a * (nstart + lower) + b <= p){
			nstart += p;
		}
		while(nstart < range){
			nprime[nstart] = false;
			nstart += p;
		}
	}
	return count(nprime.begin(), nprime.begin() + range, true);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<bool> is_prime(1000001, true);
	vector<int> primes;
	erathosthenes_sieve(is_prime, primes, 1000000);
	int t = 0;
	while(true){
		long long a, b, lower, upper;
		cin >> a;
		if(a == 0){
			break;
		}
		++t;
		cin >> b >> lower >> upper;
		cout << "Case " << t << ": " << dirichlet(is_prime, primes, a, b, lower, upper) << "\n";
	}
	return 0;
}
