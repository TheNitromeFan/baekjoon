#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double roads(int ax, int ay, int bx, int by, double p, double q, double r){
	double ret = abs(ax - bx) + abs(ay - by);
	if(p != 0){
		double ax1 = (r - q * ay) / p;
		double bx1 = (r - q * by) / p;
		ret = min(ret, abs(ax - ax1) + dist(ax1, ay, bx1, by) + abs(bx - bx1));
	}
	if(q != 0){
		double ay1 = (r - p * ax) / q;
		double by1 = (r - p * bx) / q;
		ret = min(ret, abs(ay - ay1) + dist(ax, ay1, bx, by1) + abs(by - by1));
	}
	if(p != 0 && q != 0){
		double ax1 = (r - q * ay) / p;
		double ay1 = (r - p * ax) / q;
		double bx1 = (r - q * by) / p;
		double by1 = (r - p * bx) / q;
		ret = min(ret, abs(ax - ax1) + dist(ax1, ay, bx, by1) + abs(by - by1));
		ret = min(ret, abs(ay - ay1) + dist(ax, ay1, bx1, by) + abs(bx - bx1));
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ax, ay, bx, by;
	double p, q, r;
	cin >> ax >> ay >> bx >> by >> p >> q >> r;
	cout << setprecision(11) << fixed << roads(ax, ay, bx, by, p, q, r);
	return 0;
}
