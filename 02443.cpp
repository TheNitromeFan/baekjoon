#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int main(){
	int n = 0;
	cin >> n;
	for(int i = n; i >= 1; --i){
		for(int j = n; j > i; --j)
			cout << " ";
		for(int j = 1; j <= 2*i-1; ++j)
			cout << "*";
		cout << endl;
	}
	return 0;
}
