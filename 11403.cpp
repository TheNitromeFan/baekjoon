#include <iostream>
#include <vector>

using namespace std;

vector<int> sum(vector<int> a, vector<int> b, int sz){
	vector<int> c;
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			c.push_back(a[i*sz+j] + b[i*sz+j]);
		}
	}
	return c;
}

vector<int> product(vector<int> a, vector<int> b, int sz){
	vector<int> c;
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			int elem = 0;
			for(int k = 0; k < sz; ++k){
				elem += a[i*sz+k] * b[k*sz+j];
			}
			c.push_back(elem);
		}
	}
	return c;
}

vector<int> power(vector<int> a, int sz, int exp){
	if(exp == 1){
		return a;
	}else if(exp % 2 == 0){
		return power(product(a, a, sz), sz, exp / 2);
	}else{
		return product(power(product(a, a, sz), sz, exp / 2), a, sz);
	}
}


int main(){
	int n;
	cin >> n;
	vector<int> a;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int x;
			cin >> x;
			a.push_back(x);
		}
	}
	vector<int> ans = a;
	for(int pow = 2; pow <= n; ++pow){
		ans = sum(ans, power(a, n, pow), n);
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << (ans[i*n + j] ? 1 : 0) << ' ';
		}
		cout << '\n';
	}
	return 0;
}
