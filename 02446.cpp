#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int main(){
	int n = 0;
	cin >> n;
	for(int i = 1; i <= n-1; ++i){
		for(int j = 1; j < i; ++j)
			cout << " ";
		for(int j = 1; j <= 2*n-2*i+1; ++j)
			cout << "*";
		cout << endl;
	}
	for(int j = 1; j <= n-1; ++j)
		cout << " ";
	cout << "*";
	cout << endl;
	for(int i = n-1; i >= 1; --i){
		for(int j = 1; j < i; ++j)
			cout << " ";
		for(int j = 1; j <= 2*n-2*i+1; ++j)
			cout << "*";
		cout << endl;
	}
	return 0;
}
