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
	vector<int> table(111);
	table['R'] = 0;
	table['P'] = 1;
	table['S'] = 2;
	int n, m;
	string rps, you;
	cin >> n >> m >> rps >> you;
	vector<long long> ans(n + m);
	for(int val = 0; val < 3; ++val){
		vector<complex<double>> a(n + m), b(m), c;
		for(int i = 0; i < n; ++i){
			if((table[rps[i]] + 1) % 3 == val){
				a[i] = complex<double>(1, 0);
			}
		}
		for(int j = 0; j < m; ++j){
			if(table[you[m - 1 - j]] == val){
				b[j] = complex<double>(1, 0);
			}
		}
		multiply(a, b, c);
		for(int k = 0; k < n + m; ++k){
			ans[k] += llround(c[k].real());
		}
	}
	cout << *max_element(ans.begin() + m - 1, ans.end()) << '\n';
	return 0;
}
