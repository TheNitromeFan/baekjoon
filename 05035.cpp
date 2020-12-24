#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double l, k, t1, t2, h;
	cin >> l >> k >> t1 >> t2 >> h;
	cout << setprecision(10) << fixed;
	if(h == l){
		cout << l << ' '
		<< ((k * t1 + k * t2 + l) + sqrt((k * t1 + k * t2 + l) * (k * t1 + k * t2 + l) - 4 * k * t1 * l)) / 2;
	}else if(h > l){
		cout << ((k * t1 + k * t2 + h) + sqrt((k * t1 + k * t2 + h) * (k * t1 + k * t2 + h) - 4 * k * t1 * l)) / 2
		<< ' '
		<< ((k * t1 + k * t2 + h) + sqrt((k * t1 + k * t2 + h) * (k * t1 + k * t2 + h) - 4 * k * t1 * l)) / 2;
	}else{
		cout << h << ' ' << h;
	}
	return 0;
}
