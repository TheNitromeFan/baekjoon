#include <iostream>

using namespace std;

int max_sum_of_digits(int n){
	if(n == 2){
		return 1;
	}else if(n % 3 == 0){
		return n / 3 * 7;
	}else if(n % 3 == 1){
		return (n / 3 - 1) * 7 + 4;
	}else{
		return n / 3 * 7 + 1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << max_sum_of_digits(n);
	return 0;
}
