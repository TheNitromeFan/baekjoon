#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

double norm(double x, double y, double z){
	return sqrt(x * x + y * y + z * z);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double ax, ay, az, bx, by, bz, cx, cy, cz;
	cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;
	for(int i = 0; i < 1000; ++i){
		double mid1x = (ax + ax + bx) / 3.0;
		double mid1y = (ay + ay + by) / 3.0;
		double mid1z = (az + az + bz) / 3.0;
		double mid2x = (ax + bx + bx) / 3.0;
		double mid2y = (ay + by + by) / 3.0;
		double mid2z = (az + bz + bz) / 3.0;
		double d2 = norm(mid1x - cx, mid1y - cy, mid1z - cz);
		double d3 = norm(mid2x - cx, mid2y - cy, mid2z - cz);
		if(d2 < d3){
			bx = mid2x;
			by = mid2y;
			bz = mid2z;
		}else{
			ax = mid1x;
			ay = mid1y;
			az = mid1z;
		}
	}
	cout << setprecision(11) << fixed << norm(ax - cx, ay - cy, az - cz);
	return 0;
}
