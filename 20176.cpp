#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <complex>
#define PI acos(-1)
#define MAX 60005
#define OFFSET 30000

using namespace std;

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
	int nu, nm, nl;
	vector<complex<double>> a(MAX), b(2 * MAX), c(MAX), ac;
	cin >> nu;
	for(int i = 0; i < nu; ++i){
		int x;
		cin >> x;
		a[x + OFFSET] = complex<double>(1, 0);
	}
	cin >> nm;
	for(int j = 0; j < nm; ++j){
		int y;
		cin >> y;
		b[2 * (y + OFFSET)] = complex<double>(1, 0);
	}
	cin >> nl;
	for(int k = 0; k < nl; ++k){
		int z;
		cin >> z;
		c[z + OFFSET] = complex<double>(1, 0);
	}
	multiply(a, c, ac);
	long long ans = 0;
	for(int y = 0; y < 2 * MAX; ++y){
		ans += llround(b[y].real()) * llround(ac[y].real());
	}
	cout << ans << '\n';
	return 0;
}
