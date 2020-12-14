#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	int cmp = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
	if(cmp > 0){
		return 1;
	}else if(cmp < 0){
		return -1;
	}else{
		return 0;
	}
}

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	sort(v.begin() + 1, v.end(), [&v](pair<int, int> a, pair<int, int> b){
		int cmp = ccw(v[0], a, b);
		return cmp > 0 || (cmp == 0 && a < b);
	});
	vector<pair<int, int>> hull;
	hull.push_back(v[0]);
	hull.push_back(v[1]);
	for(int i = 2; i < n; ++i){
		while(hull.size() >= 2){
			pair<int, int> a = hull[hull.size() - 2], b = hull[hull.size() - 1];
			hull.pop_back();
			if(ccw(a, b, v[i]) > 0){
				hull.push_back(b);
				break;
			}
		}
		hull.push_back(v[i]);
	}
	double ans = 0;
	for(unsigned i = 0; i < hull.size(); ++i){
		for(unsigned j = 0; j < i; ++j){
			double cmp = dist(hull[i].first, hull[i].second, hull[j].first, hull[j].second);
			if(ans < cmp){
				ans = cmp;
			}
		}
	}
	cout << setprecision(11) << ans;
	return 0;
}
