#include <iostream>

using namespace std;

bool is_prime(int n){
	if(n == 2){
		return true;
	}else if(n % 2 == 0){
		return false;
	}
	for(int p = 3; p * p <= n; p += 2){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	if(is_prime(n)){
		cout << "Yes";
	}else{
		cout << "No";
	}
	return 0;
}
