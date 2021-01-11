#include <iostream>

using namespace std;

long long x(long long n){
	long long nine = 9;
	while(nine <= n){
		nine = nine * 10 + 9;
	}
	long long ans = 0;
	while(true){
		nine /= 10;
		if(nine == 0){
			break;
		}
		if(n / nine > 9){
			return -1;
		}
		ans += n / nine;
		ans *= 10;
		n %= nine;
	}
	if(n != 0){
		return -1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long n;
		cin >> n;
		cout << x(n) << ' ';
	}
	return 0;
}
