#include <iostream>

using std::cin;
using std::cout;

int main(){
	int n = 0, x = 0;
	cin >> n >> x;
	int a = 0;
	for(int i = 0; i < n; ++i){
		cin >> a;
		if(a < x)
			cout << a << " ";
	}
	return 0;
}
