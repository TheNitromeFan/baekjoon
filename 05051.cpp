#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <complex>
#define PI acos(-1)

using namespace std;

unsigned reverse_bits(unsigned n, unsigned k){
	unsigned ret = 0;
	for(unsigned i = 0; i < k; ++i){
		ret |= ((n >> i) & 1) << (k - 1 - i);
	}
	return ret;
}

void fft(vector<complex<double>> &f, bool inverse){
	unsigned n = f.size(), k = __builtin_ctz(n);
	for(unsigned i = 0; i < n; ++i){
		unsigned j = reverse_bits(i, k);
		if(i < j){
			swap(f[i], f[j]);
		}
	}
	for(unsigned s = 2; s <= n; s *= 2){
		double t = 2 * PI / s;
		if(inverse){
			t *= -1;
		}
		complex<double> ws(cos(t), sin(t));
		for(unsigned i = 0; i < n; i += s){
			complex<double> w(1, 0);
			for(unsigned j = 0; j < s / 2; ++j){
				complex<double> tmp = f[i + j + s / 2] * w;
				f[i + j + s / 2] = f[i + j] - tmp;
				f[i + j] += tmp;
				w *= ws;
			}
		}
	}
	if(inverse){
		for(unsigned i = 0; i < n; ++i){
			f[i] /= n;
		}
	}
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	long long n;
	cin >> n;
	long long np = 1;
	while(np < 2 * n){
		np *= 2;
	}
	vector<long long> f(np);
	for(long long i = 1; i < n; ++i){
		++f[i * i % n];
	}
	vector<complex<double>> g(f.begin(), f.end()), fp(np);
	for(long long i = 0; i < n; ++i){
		fp[i] = f[(n - i) % n];
		fp[np - n + i] = f[(n - i) % n];
	}
	fft(g, false);
	fft(fp, false);
	for(long long i = 0; i < np; ++i){
		g[i] *= fp[i];
	}
	fft(g, true);
	long long ans = 0;
	for(long long i = 0; i < n; ++i){
		ans += f[i] * (llround(g[i].real()) + f[2 * i % n]);
	}
	cout << ans / 2 << '\n';
	return 0;
}
