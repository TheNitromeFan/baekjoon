#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for(int i = 0; i < n; ++i){
		cin >> p[i].first >> p[i].second;
	}
	sort(p.begin(), p.end());
	vector<pair<int, int>> min_y, max_y;
	int i = 0, j = 0;
	while(i < n && j < n){
		while(j < n && p[i].first == p[j].first){
			++j;
		}
		min_y.push_back(p[i]);
		max_y.push_back(p[j - 1]);
		i = j;
	}
	vector<double> dp[2];
	dp[0].resize(min_y.size());
	dp[1].resize(max_y.size());
	for(unsigned i = 1; i < min_y.size(); ++i){
		dp[0][i] = max(dp[0][i - 1] + dist(min_y[i - 1].first, min_y[i - 1].second, min_y[i].first, min_y[i].second),
		dp[1][i - 1] + dist(max_y[i - 1].first, max_y[i - 1].second, min_y[i].first, min_y[i].second));
		dp[1][i] = max(dp[0][i - 1] + dist(min_y[i - 1].first, min_y[i - 1].second, max_y[i].first, max_y[i].second),
		dp[1][i - 1] + dist(max_y[i - 1].first, max_y[i - 1].second, max_y[i].first, max_y[i].second));
	}
	cout << setprecision(11) << fixed << max(dp[0].back(), dp[1].back());
	return 0;
}
