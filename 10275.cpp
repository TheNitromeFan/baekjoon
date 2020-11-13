#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int log2(long long n){
	int ret = 0;
	while(n > 1){
		++ret;
		n /= 2;
	}
	return ret;
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		long long a, b;
		cin >> n >> a >> b;
		cout << (n - log2(gcd(a, b))) << '\n';
	}
	return 0;
}
