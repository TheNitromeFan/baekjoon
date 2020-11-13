#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	int xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	if((yb - ya) * (xc - xb) == (yc - yb) * (xb - xa)){
		cout << "-1" << endl;
		return 0;
	}
	long double e[3];
	e[0] = sqrt((long double)((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya)));
	e[1] = sqrt((long double)((xc - xa) * (xc - xa) + (yc - ya) * (yc - ya)));
	e[2] = sqrt((long double)((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb)));
	sort(e, e+3);
	cout << setprecision(20) << 2 * (e[2] - e[0]) << endl;
	return 0;
}
