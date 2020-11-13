#include <iostream>

using namespace std;

int exponent(int number, int base){
	int ret = 0;
	while(number >= base){
		ret += number / base;
		number /= base;
	}
	return ret;
}

int main(){
	int n, m;
	cin >> n >> m;
	int factor2 = exponent(n, 2) - exponent(m, 2) - exponent(n-m, 2);
	int factor5 = exponent(n, 5) - exponent(m, 5) - exponent(n-m, 5);
	cout << min(factor2, factor5) << endl;
	return 0;
}
