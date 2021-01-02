#include <iostream>

using namespace std;

bool a(int n){
	if(n <= 5){
		return false;
	}
	int sum_of_digits = 0;
	while(n > 0){
		sum_of_digits += n % 10;
		n /= 10;
	}
	return sum_of_digits % 2 == 1;
}

bool b(int n){
	if(n == 1){
		return false;
	}else if(n == 2 || n == 4){
		return true;
	}
	int prime_factors = 0;
	int p = 2;
	while(n > 1){
		if(n % p == 0){
			++prime_factors;
		}
		while(n % p == 0){
			n /= p;
		}
		++p;
	}
	return prime_factors % 2 == 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	bool lee = a(n), lim = b(n);
	int ans;
	if(lee && lim){
		ans = 4;
	}else if(lee){
		ans = 1;
	}else if(lim){
		ans = 2;
	}else{
		ans = 3;
	}
	cout << ans;
	return 0;
}
