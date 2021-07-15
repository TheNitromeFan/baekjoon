#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <complex>
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
	string num1, num2;
	cin >> num1 >> num2;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	vector<complex<double>> a, b, c;
	for(char ch : num1){
		a.push_back(complex<double>(ch - '0', 0));
	}
	for(char ch : num2){
		b.push_back(complex<double>(ch - '0', 0));
	}
	multiply(a, b, c);
	while(!c.empty() && c.back() == complex<double>(0, 0)){
		c.pop_back();
	}
	if(c.empty()){
		c.push_back(complex<double>(0, 0));
	}
	string prod;
	for(vector<complex<double>>::size_type idx = 0; idx < c.size(); ++idx){
		complex<double> z = c[idx];
		long long n = llround(z.real());
		if(n >= 10){
			if(idx == c.size() - 1){
				c.push_back(complex<double>(n / 10, 0));
			}else{
				c[idx + 1] += complex<double>(n / 10, 0);
			}
			c[idx] = complex<double>(n % 10, 0);
		}
	}
	reverse(c.begin(), c.end());
	for(complex<double> z : c){
		cout << llround(z.real());
	}
	return 0;
}
