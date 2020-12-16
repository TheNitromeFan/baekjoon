#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	cin >> x >> y;
	int n;
	cin >> n;
	double y0 = y;
	for(int i = 0; i < n; ++i){
		int lower, upper;
		double factor;
		cin >> lower >> upper >> factor;
		y0 -= (1 - factor) * (upper - lower);
	}
	cout << setprecision(11) << x / y0;
	return 0;
}
