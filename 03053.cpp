#include <iostream>
#include <cmath>

#define PI (acos(-1.0))

using std::cin;
using std::cout;
using std::endl;
using std::fixed;

int main(){
	double r = 0.0;
	cin >> r;
	cout << fixed << PI * r * r << endl;
	cout << fixed << 2.0 * r * r << endl;
	return 0;
}
