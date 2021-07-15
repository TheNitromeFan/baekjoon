#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double &x, double &y){
	double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
	x = x1 + t * (x2 - x1);
	y = y1 + t * (y2 - y1);
}

double area(double x1, double y1, double x2, double y2, double x3, double y3){
	return fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		double ax = 0, ay = 0, bx, by = 0, cx, cy, dx, dy;
		cin >> bx >> cx >> cy >> dx >> dy;
		double apx = (bx + cx) / 2, apy = (by + cy) / 2;
		double bpx = (cx + dx) / 2, bpy = (cy + dy) / 2;
		double cpx = (dx + ax) / 2, cpy = (dy + ay) / 2;
		double dpx = (ax + bx) / 2, dpy = (ay + by) / 2;
		double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
		intersect(ax, ay, apx, apy, bx, by, bpx, bpy, x1, y1);
		intersect(bx, by, bpx, bpy, cx, cy, cpx, cpy, x2, y2);
		intersect(cx, cy, cpx, cpy, dx, dy, dpx, dpy, x3, y3);
		intersect(dx, dy, dpx, dpy, ax, ay, apx, apy, x4, y4);
		cout << fixed << setprecision(3);
		cout << area(ax, ay, bx, by, x1, y1) << ' ';
		cout << area(bx, by, cx, cy, x2, y2) << ' ';
		cout << area(cx, cy, dx, dy, x3, y3) << ' ';
		cout << area(dx, dy, ax, ay, x4, y4) << ' ';
		cout << (area(x1, y1, x2, y2, x3, y3) + area(x3, y3, x4, y4, x1, y1)) << ' ';
		double perim = dist(x1, y1, x2, y2) + dist(x2, y2, x3, y3) + dist(x3, y3, x4, y4) + dist(x4, y4, x1, y1);
		cout << (long long)ceil(perim) << '\n';
	}
	return 0;
}
