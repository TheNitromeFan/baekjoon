#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <complex>
#define MAX 202020
#define PI acos(-1)

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
	int n, m;
	cin >> n;
	vector<complex<double>> a(MAX);
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		a[k] = complex<double>(1, 0);
	}
	a[0] = complex<double>(1, 0);
	vector<complex<double>> b = a, c;
	multiply(a, b, c);
	/*
	for(vector<complex<double>>::size_type i = 0; i < 20; ++i){
		cout << i << ": " << c[i].real() << '\n';
	}
	*/
	cin >> m;
	int cnt = 0;
	for(int j = 0; j < m; ++j){
		int d;
		cin >> d;
		if(llround(c[d].real()) > 0){
			++cnt;
		}
	}
	cout << cnt << '\n';
	return 0;
}
