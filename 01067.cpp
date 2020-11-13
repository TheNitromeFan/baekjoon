#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <complex>
#define pi acos(-1)

using namespace std;

void fft(vector<complex<double>> &f, complex<double> w){
	auto n = f.size();
	if(n == 1){
		return;
	}
	vector<complex<double>> even(n >> 1), odd(n >> 1);
	for(auto i = 0; i < n; ++i){
		if(i & 1){
			odd[i >> 1] = f[i];
		}else{
			even[i >> 1] = f[i];
		}
	}
	fft(even, w * w);
	fft(odd, w * w);
	complex<double> wp(1, 0);
	for(auto i = 0; i < n / 2; ++i){
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
	}
}

vector<complex<double>> mult(vector<complex<double>> a, vector<complex<double>> b){
	auto n = 1;
	while(n <= a.size() || n <= b.size()){
		n <<= 1;
	}
	a.resize(n);
	b.resize(n);
	vector<complex<double>> c(n);
	complex<double> w(cos(2 * pi / n), sin(2 * pi / n));
	fft(a, w);
	fft(b, w);
	for(auto i = 0; i < n; ++i){
		c[i] = a[i] * b[i];
	}
	fft(c, complex<double>(1, 0) / w);
	for(auto i = 0; i < n; ++i){
		c[i] /= complex<double>(n, 0);
		c[i] = complex<double>(llround(c[i].real()), llround(c[i].imag()));
	}
	return c;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> x(2 * n, 0), y(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &x[i]);
		x[i + n] = x[i];
	}
	for(int i = n-1; i >= 0; --i){
		scanf("%d", &y[i]);
	}
	vector<complex<double>> a, b;
	for(int m : x){
		a.push_back(complex<double>(m, 0));
	}
	for(int m : y){
		b.push_back(complex<double>(m, 0));
	}
	vector<complex<double>> c = mult(a, b);
	long long ans = 0;
	for(auto i = 0; i < c.size(); ++i){
		long long cmp = llround(c[i].real());
		if(cmp > ans){
			ans = cmp;
		}
	}
	printf("%lld", ans);
	return 0;
}
