#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a%b);
	}
}

void factors(vector<int> &f, int n){
	for(int p = 1; p*p <= n; ++p){
		if(n % p == 0){
			f.push_back(p);
		}
	}
	if(n == 1){
		return;
	}
	int fs = f.size();
	int tmp = f[fs-1];
	if(tmp * tmp < n){
		f.push_back(n/tmp);
	}
	for(int i = fs-2; i >= 0; --i){
		f.push_back(n/f[i]);
	}
}

int main(){
	int n;
	cin >> n;
	int g;
	if(n == 2){
		int a, b;
		cin >> a >> b;
		g = gcd(a, b);
	}else{
		int a, b, c;
		cin >> a >> b >> c;
		g = gcd(gcd(a, b), c);
	}
	vector<int> v;
	factors(v, g);
	for(int x : v){
		cout << x << '\n';
	}
	return 0;
}
