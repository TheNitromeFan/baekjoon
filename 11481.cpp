#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>
#define PI acos(-1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	double g;
	cin >> n >> g;
	vector<pair<int, int>> slopes(n);
	for(int i = 0; i < n; ++i){
		cin >> slopes[i].first >> slopes[i].second;
	}
	reverse(slopes.begin(), slopes.end());
	double v0 = 0;
	vector<double> ans;
	for(pair<int, int> p : slopes){
		int d = p.first, theta = p.second;
		double angle = theta * PI / 180;
		double v = sqrt(v0 * v0 + 2 * g * cos(angle) * d);
		ans.push_back(v);
		v0 = v;
	}
	reverse(ans.begin(), ans.end());
	for(double v : ans){
		cout << fixed << setprecision(9) << v << '\n';
	}
	return 0;
}
