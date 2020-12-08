#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double cross(double x, double y, double w){
	return 1 / (1 / sqrt(x * x - w * w) + 1 / sqrt(y * y - w * w));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double x, y, c;
	cin >> x >> y >> c;
	double low = 0, high = min(x, y) - 0.00001;
	double mid = (low + high) / 2;
	for(int i = 0; i < 100; ++i){
		// cout << cross(x, y, mid) << '\n';
		if(cross(x, y, mid) > c){
			low = mid;
		}else{
			high = mid;
		}
		mid = (low + high) / 2;
	}
	cout << fixed << setprecision(3) << mid;
	return 0;
}
