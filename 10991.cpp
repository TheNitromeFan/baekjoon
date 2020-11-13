#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int main(){
	int n = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n-i; ++j){
			cout << " ";
		}
		cout << "*";
		for(int j = 1; j <= i-1; ++j){
			cout << " *";
		}
		cout << endl;
	}
	return 0;
}
