#include <iostream>

using std::cin;
using std::cout;

int main(){
	int sum = 0, n = 0;
	for(int i = 0; i < 5; ++i){
		cin >> n;
		sum += n*n;
	}
	cout << sum % 10;
	return 0;
}
