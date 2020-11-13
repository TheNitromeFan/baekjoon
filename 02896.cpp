#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	int a, b, c, i, j, k;
	cin >> a >> b >> c >> i >> j >> k;
	double proportions = min(min(a / (double)i, b / (double)j), c / (double)k);
	cout << setprecision(10) << a - proportions * i << ' ';
	cout << setprecision(10) << b - proportions * j << ' ';
	cout << setprecision(10) << c - proportions * k;
	return 0;
}
