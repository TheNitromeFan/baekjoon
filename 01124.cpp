#include <iostream>
#include <vector>

using namespace std;

void factorize(vector<int> &f, int n){
	while(n % 2 == 0){
		f.push_back(2);
		n /= 2;
	}
	for(int p = 3; p * p <= n; ++p){
		while(n % p == 0){
			f.push_back(p);
			n /= p;
		}
	}
	if(n > 1){
		f.push_back(n);
	}
}

bool is_prime(int n){
	vector<int> factors;
	factorize(factors, n);
	return factors.size() == 1;
}

bool is_underprime(int n){
	vector<int> factors;
	factorize(factors, n);
	return is_prime(factors.size());
}

int main(){
	int a, b;
	cin >> a >> b;
	int cnt = 0;
	for(int i = a; i <= b; ++i){
		if(is_underprime(i)){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
