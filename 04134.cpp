#include <iostream>

using namespace std;

bool prime(long long n){
	if(n == 0 || n == 1){
		return false;
	}else if(n == 2){
		return true;
	}else if(n % 2 == 0){
		return false;
	}
	for(long long p = 3; p * p <= n; p += 2){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long n;
		cin >> n;
		while(!prime(n)){
			++n;
		}
		cout << n << "\n";
	}
	return 0;
}
