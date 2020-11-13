#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::setprecision;

int main(){
	double a, b;
	cin >> a >> b;
	cout << setprecision(9) << a/b;
	return 0;
}
