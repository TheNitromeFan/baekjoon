#include <iostream>
#include <iomanip>
#include <cmath>
#define PI acos(-1)

using namespace std;

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double overlap(double x1, double y1, double r1, double x2, double y2, double r2){
	double d = dist(x1, y1, x2, y2);
	if(d >= r1 + r2){
		return 0;
	}else if(d + r1 <= r2){
		return PI * r1 * r1;
	}else if(d + r2 <= r1){
		return PI * r2 * r2;
	}
	double theta1 = 2 * acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
	double theta2 = 2 * acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
	return r1 * r1 * theta1 / 2 - r1 * r1 * sin(theta1) / 2
	+ r2 * r2 * theta2 / 2 - r2 * r2 * sin(theta2) / 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	cout << setprecision(3) << fixed << overlap(x1, y1, r1, x2, y2, r2);
	return 0;
}
