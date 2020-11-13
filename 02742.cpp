#include <iostream>

using std::cin;
using std::cout;

int main(){
	int n = 0;
	cin >> n;
	for(int i = n; i >= 1; --i)
		cout << i << '\n';
	return 0;
}
