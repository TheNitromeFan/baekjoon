#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int x1, y1, d1, x2, y2, d2;
		cin >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;
		double theta1 = d1 * PI / 180;
		double theta2 = d2 * PI / 180;
		double x = ((cos(theta1) * x1 - sin(theta1) * y1) * sin(theta2) - (cos(theta2) * x2 - sin(theta2) * y2) * sin(theta1)) / (cos(theta1) * sin(theta2) - sin(theta1) * cos(theta2));
		double y = ((cos(theta1) * x1 - sin(theta1) * y1) * cos(theta2) - (cos(theta2) * x2 - sin(theta2) * y2) * cos(theta1)) / (cos(theta1) * sin(theta2) - sin(theta1) * cos(theta2));
		cout << fixed << setprecision(4) << x << ' ' << y << '\n';
	}
	return 0;
}
