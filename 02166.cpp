#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

int ccw(double x1, double y1, double x2, double y2, double x3, double y3){
	double cmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if(cmp > 0){
		return 1;
	}else if(cmp < 0){
		return -1;
	}else{
		return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<double, double>> p(n);
	for(int i = 0; i < n; ++i){
		cin >> p[i].first >> p[i].second;
	}
	double area = 0;
	double x1 = p[0].first, y1 = p[0].second;
	for(int i = 1; i + 1 < n; ++i){
		double x2 = p[i].first, y2 = p[i].second, x3 = p[i + 1].first, y3 = p[i + 1].second;
		double triangle = abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
		area += ccw(x1, y1, x2, y2, x3, y3) * triangle;
	}
	cout << setprecision(1) << fixed << abs(area);
	return 0;
}
