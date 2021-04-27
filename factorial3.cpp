#include <bits/stdc++.h>
#define PI acos(-1)

using namespace std;

typedef complex<long double> cd;
typedef int64_t i64;

void fft(vector<cd> &a, bool inv){
	int n = (int)a.size();
	for(int i = 1, j = 0; i < n; ++i){
		int cmp = (n >> 1);
		while(j >= cmp){
			j -= cmp;
			cmp >>= 1;
		}
		j += cmp;
		if(i < j){
			swap(a[i], a[j]);
		}
	}
	double angle = 2 * PI / n;
	if(inv){
		angle *= -1;
	}
	vector<cd> unity(n / 2);
	for(int i = 0; i < n / 2; ++i){
		unity[i] = cd(cos(angle * i), sin(angle * i));
	}
	for(int i = 2; i <= n; i <<= 1){
		int inc = n / i;
		for(int j = 0; j < n; j += i){
			for(int k = 0; k < i / 2; ++k){
				cd c1 = a[j + k], c2 = a[j + k + i / 2] * unity[inc * k];
				a[j + k] = c1 + c2;
				a[j + k + i / 2] = c1 - c2;
			}
		}
	}
	if(inv){
		for(int i = 0; i < n; ++i){
			a[i] /= n;
		}
	}
}

vector<i64> multiply(vector<i64> &v, vector<i64> &w, i64 mod){
	int n = 2;
	while(n < (int)(v.size() + w.size())){
		n <<= 1;
	}
	vector<cd> v1(n), w1(n), r1(n), r2(n);
	for(int i = 0; i < (int)v.size(); ++i){
		v1[i] = cd(v[i] >> 15, v[i] & 32767);
	}
	for(int i = 0; i < (int)w.size(); ++i){
		w1[i] = cd(w[i] >> 15, w[i] & 32767);
	}
	fft(v1, false);
	fft(w1, false);
	for(int i = 0; i < n; ++i){
		int j = (i ? (n - i) : i);
		cd c1 = (v1[i] + conj(v1[j])) * cd(0.5, 0);
		cd c2 = (v1[i] - conj(v1[j])) * cd(0, -0.5);
		cd c3 = (w1[i] + conj(w1[j])) * cd(0.5, 0);
		cd c4 = (w1[i] - conj(w1[j])) * cd(0, -0.5);
		r1[i] = (c1 * c3) + (c1 * c4) * cd(0, 1);
		r2[i] = (c2 * c3) + (c2 * c4) * cd(0, 1);
	}
	fft(r1, true);
	fft(r2, true);
	vector<i64> ret(n);
	for(int i = 0; i < n; ++i){
		i64 av = (i64)round(r1[i].real()) % mod;
		i64 bv = ((i64)round(r1[i].imag()) + (i64)round(r2[i].real())) % mod;
		i64 cv = (i64)round(r2[i].imag()) % mod;
		ret[i] = (av << 30) + (bv << 15) + cv;
		ret[i] %= mod;
		ret[i] += mod;
		ret[i] %= mod;
	}
	return ret;
}

vector<i64> lagrange(vector<i64> &eval, i64 p){
	int d = (int)eval.size() - 1;
	auto mul = [p](i64 a, i64 b){
		return a * b % p;
	};
	auto intPow = [&mul](i64 a, i64 b){
		i64 res = 1;
		while(b){
			if(b & 1){
				res = mul(res, a);
			}
			a = mul(a, a);
			b >>= 1;
		}
		return res;
	};
	auto modInv = [&intPow, p](i64 a){
		return intPow(a, p - 2);
	};
	vector<i64> fact(4 * d + 2), invFact(4 * d + 2);
	fact[0] = 1;
	for(int i = 1; i < 4 * d + 2; ++i){
		fact[i] = mul(fact[i - 1], i);
	}
	invFact[4 * d + 1] = modInv(fact[4 * d + 1]);
	for(int i = 4 * d; i >= 0; --i){
		invFact[i] = mul(invFact[i + 1], i + 1);
	}
	vector<i64> f(d + 1);
	for(int i = 0; i <= d; ++i){
		f[i] = eval[i];
		f[i] = mul(f[i], invFact[i]);
		f[i] = mul(f[i], invFact[d - i]);
		if((d - i) & 1){
			f[i] = p - f[i];
		}
		if(f[i] == p){
			f[i] = 0;
		}
	}
	vector<i64> inv(4 * d + 2);
	for(int i = 1; i < 4 * d + 2; ++i){
		inv[i] = mul(fact[i - 1], invFact[i]);
	}
	vector<i64> g(4 * d + 2);
	g[d + 1] = 1;
	for(int j = 0; j <= d; ++j){
		g[d + 1] = mul(g[d + 1], d + 1 - j);
	}
	for(int i = d + 2; i < 4 * d + 2; ++i){
		g[i] = mul(g[i - 1], mul(i, inv[i - d - 1]));
	}
	vector<i64> conv = multiply(f, inv, p);
	vector<i64> ret(4 * d + 2);
	for(int i = 0; i <= d; ++i){
		ret[i] = eval[i];
	}
	for(int i = d + 1; i < 4 * d + 2; ++i){
		ret[i] = mul(g[i], conv[i]);
	}
	return ret;
}

vector<i64> squarePoly(vector<i64> poly, i64 p){
	vector<i64> s = lagrange(poly, p);
	vector<i64> ret(s.size() / 2);
	auto mul = [p](i64 a, i64 b){
		return a * b % p;
	};
	for(int i = 0; i < (int)s.size() / 2; ++i){
		ret[i] = mul(s[2 * i], s[2 * i + 1]);
	}
	return ret;
}

int main(){
	i64 n, p;
	cin >> n >> p;
	if(p < 100){
		i64 ans = 1;
		for(int i = 1; i <= n; ++i){
			ans *= i;
			ans %= p;
		}
		cout << ans << endl;
		return 0;
	}
	i64 d = 1;
	vector<i64> fact = {1 % p, 2 % p};
	while(n > d * (d + 1)){
		fact = squarePoly(fact, p);
		d <<= 1;
	}
	auto mul = [p](i64 a, i64 b){
		return a * b % p;
	};
	i64 ans = 1;
	i64 sz = n / d;
	for(i64 i = 0; i < sz; ++i){
		ans = mul(ans, fact[i]);
	}
	for(i64 i = sz * d + 1; i <= n; ++i){
		ans = mul(ans, i);
	}
	cout << ans << endl;
	return 0;
}
