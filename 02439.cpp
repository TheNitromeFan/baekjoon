#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int main(){
	int n = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = n; j >= 1; --j){
			if(j <= i)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}
