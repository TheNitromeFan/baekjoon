#include <iostream>

using namespace std;

int max_copy(int n){
	int place = 1;
	int result = 0;
	while(n > 0){
		int digit = n % 10;
		if(digit == 5){
			result += 6 * place;
		}else{
			result += digit * place;
		}
		n /= 10;
		place *= 10;
	}
	return result;
}

int min_copy(int n){
	int place = 1;
	int result = 0;
	while(n > 0){
		int digit = n % 10;
		if(digit == 6){
			result += 5 * place;
		}else{
			result += digit * place;
		}
		n /= 10;
		place *= 10;
	}
	return result;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << min_copy(a) + min_copy(b) << ' ' << max_copy(a) + max_copy(b) << endl;
	return 0;
}
