#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double leg(double h, double a){
	return sqrt(h * h - a * a);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double r, l;
	cin >> r >> l;
	if(l >= 2 * r){
		cout << fixed << setprecision(12) << 0.0 << ' ' << -r << '\n' << 0.0 << ' ' << r;
	}else{
		double x = leg(r, l / 2);
		cout << fixed << setprecision(12) << x << ' ' << -(l / 2) << '\n' << x << ' ' << l / 2;
	}
	return 0;
}
