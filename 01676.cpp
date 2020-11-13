#include <iostream>

using std::cin;
using std::cout;

int main(){
	int n = 0;
	cin >> n;
	int zeroes = 0;
	while(n > 0){
		zeroes += n / 5;
		n /= 5;
	}
	cout << zeroes;
	return 0;
}
