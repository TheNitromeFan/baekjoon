#include <iostream>

using namespace std;

bool prime(int n){
	if(n == 1){
		return false;
	}
	for(int p = 2; p * p <= n; ++p){
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
		int sum = 0;
		for(int j = 0; j < 5; ++j){
			int n;
			cin >> n;
			while(!prime(n)){
				++n;
			}
			sum += n;
		}
		cout << sum << '\n';
	}
	return 0;
}
