#include <iostream>

using namespace std;

int digits(int n){
	if(n == 1){
		return 1;
	}
	int ret = 0;
	for(int digit = 9; digit > 1; --digit){
		while(n % digit == 0){
			n /= digit;
			++ret;
		}
	}
	return n == 1 ? ret : -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		cout << digits(n) << '\n';
	}
	return 0;
}
