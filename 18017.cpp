#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long c = 299792458;
	double a, b;
	cin >> a >> b;
	cout << fixed << setprecision(12) << (a + b) / (1 + a * b / c / c);
	return 0;
}
