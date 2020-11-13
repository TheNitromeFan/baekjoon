#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int n = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int a = 0, b = 0;
		cin >> a >> b;
		cout << "Case #" << i << ": " << a+b << endl;
	}
	return 0;
}
