#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double ax, ay, bx, by, cx, cy, dx, dy;
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
	for(int i = 0; i < 1000; ++i){
		double f1x = (2 * ax + bx) / 3, f1y = (2 * ay + by) / 3;
		double g1x = (2 * cx + dx) / 3, g1y = (2 * cy + dy) / 3;
		double f2x = (ax + 2 * bx) / 3, f2y = (ay + 2 * by) / 3;
		double g2x = (cx + 2 * dx) / 3, g2y = (cy + 2 * dy) / 3;
		double d1 = dist(f1x, f1y, g1x, g1y), d2 = dist(f2x, f2y, g2x, g2y);
		if(d1 < d2){
			bx = f2x;
			by = f2y;
			dx = g2x;
			dy = g2y;
		}else{
			ax = f1x;
			ay = f1y;
			cx = g1x;
			cy = g1y;
		}
	}
	cout << fixed << setprecision(12) << dist(ax, ay, cx, cy);
	return 0;
}
