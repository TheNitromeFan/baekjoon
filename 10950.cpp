#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int n = 0;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int a = 0, b = 0;
		cin >> a >> b;
		cout << a+b << endl;
	}
	return 0;
}
