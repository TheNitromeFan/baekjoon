#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

double dist(double x, double y){
	return sqrt(x * x + y * y);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	double a;
	cin >> n >> a;
	vector<pair<double, double>> v(n);
	for(int i = 0; i < n; ++i){
		double x, y;
		cin >> x >> y >> v[i].second;
		v[i].first = dist(x, y);
	}
	sort(v.begin(), v.end());
	vector<double> c(n), d(n);
	c[0] = v[0].second;
	d[0] = v[0].second * v[0].first;
	for(int i = 1; i <n; ++i){
		c[i] = c[i - 1] + v[i].second;
		d[i] = d[i - 1] + v[i].second * v[i].first;
	}
	double max_yield = 0;
	for(int i = 0; i < n - 1; ++i){
		max_yield = max(max_yield, c[i] * v[i].first - d[i] - a * v[i].first * v[i].first);
		double r = c[i] / (2 * a);
		if(r >= v[i].first && r <= v[i + 1].first){
			max_yield = max(max_yield, c[i] * r - d[i] - a * r * r);
		}
	}
	double r = c[n - 1] / (2 * a);
	if(r >= v[n - 1].first){
		max_yield = max(max_yield, c[n - 1] * r - d[n - 1] - a * r * r);
	}
	cout << fixed << setprecision(9) << max_yield << '\n';
	return 0;
}
