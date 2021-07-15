#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;

double dist(vector<pair<int, int>> &vec){
	double x = 0;
	double v = 0;
	for(pair<int, int> p : vec){
		double a = p.first, t = p.second;
		x += v * t + 0.5 * a * t * t;
		v += a * t;
	}
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		v[i] = make_pair(x, y);
	}
	double x0 = dist(v);
	sort(v.begin(), v.end(), greater<pair<int, int>>());
	double x1 = dist(v);
	cout << fixed << setprecision(1) << x1 - x0 << '\n';
	return 0;
}
