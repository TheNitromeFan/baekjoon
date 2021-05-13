#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

double area(double x1, double y1, double x2, double y2, double x3, double y3){
	return fabs(x2 * y1 + x3 * y2 + x1 * y3 - x1 * y2 - x2 * y3 - x3 * y1) / 2;
}

void update(double &ans1, double &ans2, double a1, double a2){
	if(a1 > a2){
		swap(a1, a2);
	}
	if(a2 - a1 < ans2 - ans1){
		ans1 = a1;
		ans2 = a2;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	double total = area(x1, y1, x2, y2, x3, y3) + area(x3, y3, x4, y4, x1, y1);
	double ans1 = 0, ans2 = total;
	double a1 = 0;
	update(ans1, ans2, area(x1, y1, x2, y2, x3, y3), area(x3, y3, x4, y4, x1, y1));
	update(ans1, ans2, area(x2, y2, x3, y3, x4, y4), area(x4, y4, x1, y1, x2, y2));
	a1 = area(x1, y1, x2, y2, (x2 + x3) / 2, (y2 + y3) / 2);
	update(ans1, ans2, a1, total - a1);
	a1 = area(x1, y1, x2, y2, (x4 + x1) / 2, (y4 + y1) / 2);
	update(ans1, ans2, a1, total - a1);
	a1 = area(x2, y2, x3, y3, (x3 + x4) / 2, (y3 + y4) / 2);
	update(ans1, ans2, a1, total - a1);
	a1 = area(x2, y2, x3, y3, (x1 + x2) / 2, (y1 + y2) / 2);
	update(ans1, ans2, a1, total - a1);
	a1 = area(x3, y3, x4, y4, (x4 + x1) / 2, (y4 + y1) / 2);
	update(ans1, ans2, a1, total - a1);
	a1 = area(x3, y3, x4, y4, (x2 + x3) / 2, (y2 + y3) / 2);
	update(ans1, ans2, a1, total - a1);
	a1 = area(x4, y4, x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
	update(ans1, ans2, a1, total - a1);
	a1 = area(x4, y4, x1, y1, (x3 + x4) / 2, (y3 + y4) / 2);
	update(ans1, ans2, a1, total - a1);
	a1 = area(x1, y1, x2, y2, (x2 + x3) / 2, (y2 + y3) / 2)
	+ area((x2 + x3) / 2, (y2 + y3) / 2, (x4 + x1) / 2, (y4 + y1) / 2, x1, y1);
	update(ans1, ans2, a1, total - a1);
	a1 = area(x2, y2, x3, y3, (x3 + x4) / 2, (y3 + y4) / 2)
	+ area((x3 + x4) / 2, (y3 + y4) / 2, (x1 + x2) / 2, (y1 + y2) / 2, x2, y2);
	update(ans1, ans2, a1, total - a1);
	cout << fixed << setprecision(6) << ans1 << ' ' << ans2;
	return 0;
}
