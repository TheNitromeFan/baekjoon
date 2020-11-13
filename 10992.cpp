#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int main(){
	int n = 0;
	cin >> n;
	for(int j = 1; j <= n-1; ++j){
		cout << " ";
	}
	cout << "*" << endl;
	if(n == 1){
		return 0;
	}
	for(int i = 2; i <= n-1; ++i){
		for(int j = 1; j <= n-i; ++j){
			cout << " ";
		}
		cout << "*";
		for(int j = 1; j <= 2*i-3; ++j){
			cout << " ";
		}
		cout << "*" << endl;
	}
	for(int j = 1; j <= 2*n-1; ++j){
		cout << "*";
	}
	cout << endl;
	return 0;
}
