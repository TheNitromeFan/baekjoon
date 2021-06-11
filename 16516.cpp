#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<double, double>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	double lipschitz = 0;
	for(int i = 0; i + 1 < n; ++i){
		double x1 = v[i].first, y1 = v[i].second, x2 = v[i + 1].first, y2 = v[i + 1].second;
		lipschitz = max(lipschitz, fabs(y2 - y1) / (x2 - x1));
	}
	cout << fixed << setprecision(9) << lipschitz;
	return 0;
}
