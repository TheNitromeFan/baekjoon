#include <iostream>

using std::cin;
using std::cout;

static int gcd(int a, int b){
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main(){
	int t = 0;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int a = 0, b = 0;
		cin >> a >> b;
		cout << a / gcd(a, b) * b << "\n";
	}
	return 0;
}
