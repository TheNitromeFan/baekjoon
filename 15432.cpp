#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int d, s;
	cin >> d >> s;
	double low = 10e-9, high = 10e9;
	for(int i = 0; i < 1000; ++i){
		double a = (low + high) / 2;
		if(a + s > a * cosh(d / (2 * a))){
			high = a;
		}else{
			low = a;
		}
	}
	cout << setprecision(9) << fixed << 2 * low * sinh(d / (2 * low));
	return 0;
}
