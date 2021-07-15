#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <complex>
#define PI acos(-1)
#define MAX 1000000

using namespace std;

void erathosthenes_sieve(vector<int> &primes, int limit){
	vector<bool> is_prime(limit + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 4; i <= limit; i += 2){
		is_prime[i] = false;
	}
	for(int p = 3; p * p <= limit; p += 2){
		for(int i = p * p; i <= limit; i += 2 * p){
			is_prime[i] = false;
		}
	}
	for(int i = 0; i <= limit; ++i){
		if(is_prime[i]){
			primes.push_back(i);
		}
	}
}

void fft(vector<complex<double>> &f, complex<double> w){
	vector<complex<double>>::size_type n = f.size();
	if(n == 1){
		return;
	}
	vector<complex<double>> even(n / 2), odd(n / 2);
	for(vector<complex<double>>::size_type i = 0; i < n; ++i){
		if(i % 2 == 1){
			odd[i / 2] = f[i];
		}else{
			even[i / 2] = f[i];
		}
	}
	fft(even, w * w);
	fft(odd, w * w);
	complex<double> wp(1, 0);
	for(vector<complex<double>>::size_type i = 0; i < n / 2; ++i){
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
	}
}

void multiply(vector<complex<double>> &a, vector<complex<double>> &b, vector<complex<double>> &c){
	vector<complex<double>>::size_type n = 1;
	while(n <= a.size() || n <= b.size()){
		n *= 2;
	}
	n *= 2;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	complex<double> w(cos(2 * PI / n), sin(2 * PI / n));
	fft(a, w);
	fft(b, w);
	for(vector<complex<double>>::size_type i = 0; i < n; ++i){
		c[i] = a[i] * b[i];
	}
	fft(c, complex<double>(1, 0) / w);
	for(vector<complex<double>>::size_type i = 0; i < n; ++i){
		c[i] /= complex<double>(n, 0);
		c[i] = complex<double>(llround(c[i].real()), llround(c[i].imag()));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> primes, semiprimes;
	erathosthenes_sieve(primes, MAX);
	for(int prime : primes){
		if(2 * prime >= MAX){
			break;
		}
		semiprimes.push_back(2 * prime);
	}
	vector<complex<double>> a(MAX), b(MAX), c;
	for(unsigned idx = 1; idx < primes.size(); ++idx){
		a[primes[idx]] = complex<double>(1, 0);
	}
	for(unsigned idx = 0; idx < semiprimes.size(); ++idx){
		b[semiprimes[idx]] = complex<double>(1, 0);
	}
	multiply(a, b, c);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		cout << llround(c[n].real()) << '\n';
	}
	return 0;
}
