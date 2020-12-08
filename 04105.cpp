#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double shoelace(double x1, double y1, double x2, double y2, double x3, double y3){
	return abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		double ax, ay, bx, by, cx, cy, dx, dy, ex, ey, fx, fy;
		cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> ex >> ey >> fx >> fy;
		if(ax == 0 && ay == 0 && bx == 0 && by == 0 && cx == 0 && cy == 0 && dx == 0 && dy == 0
		&& ex == 0 && ey == 0 && fx == 0 && fy == 0){
			break;
		}
		double scale = shoelace(dx, dy, ex, ey, fx, fy) / 2 / shoelace(ax, ay, bx, by, cx, cy);
		double hx = (1 - scale) * ax + scale * cx;
		double hy = (1 - scale) * ay + scale * cy;
		double gx = bx + hx - ax;
		double gy = by + hy - ay;
		cout << setprecision(3) << fixed << gx << ' ' << gy << ' ' << hx << ' ' << hy << '\n';
	}
	return 0;
}
