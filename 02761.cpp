#include <iostream>
#include <cmath>
#define PI acos(-1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double d, h;
	cin >> d >> h;
	while(true){
		double alpha, beta, gamma;
		cin >> alpha >> beta >> gamma;
		if(alpha <= 0 || beta <= 0 || gamma <= 0){
			break;
		}
		double a = alpha / 180 * PI;
		double b = beta / 180 * PI;
		double c = gamma / 180 * PI;
		double sin2a = sin(a) * sin(a);
		double sin2b = sin(b) * sin(b);
		double sin2c = sin(c) * sin(c);
		cout << (int)round(sqrt(2 * d * d / (1 / sin2a + 1 / sin2c - 2 / sin2b)) + h) << '\n';
	}
	return 0;
}
