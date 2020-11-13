#include <iostream>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int x, y;
	cin >> x >> y;
	int g = gcd(x, y);
	int a = x/g, b = y/g;
	cout << (a + b - 1) * g;
	return 0;
}
