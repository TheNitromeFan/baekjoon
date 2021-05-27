#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

long long ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3){
	return (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
}

double dist(pair<long long, long long> p1, pair<long long, long long> p2){
	return sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
}

double dist(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p0){
	return abs(ccw(p1, p2, p0)) / dist(p1, p2);
}

void convex_hull(vector<pair<long long, long long>> &p, vector<pair<long long, long long>> &h, int n){
	sort(p.begin(), p.end());
	sort(p.begin() + 1, p.end(), [&](pair<long long, long long> a, pair<long long, long long> b){
		int cmp = ccw(p[0], a, b);
		return cmp > 0 || (cmp == 0 && dist(p[0], a) < dist(p[0], b));
	});
	h.push_back(p[0]);
	h.push_back(p[1]);
	for(int i = 2; i < n; ++i){
		while(h.size() >= 2){
			pair<long long, long long> b = h.back();
			h.pop_back();
			pair<long long, long long> a = h.back();
			if(ccw(a, b, p[i]) > 0){
				h.push_back(b);
				break;
			}
		}
		h.push_back(p[i]);
	}
}

double max_width(vector<pair<long long, long long>> &p, int n){
	vector<pair<long long, long long>> h;
	convex_hull(p, h, n);
	n = (int)h.size();
	h.push_back(h[0]);
	double ret = 1e16;
	for(int i = 0; i < n; ++i){
		double tmp = 0;
		for(int j = 0; j < n; ++j){
			tmp = max(tmp, dist(h[i], h[i + 1], h[j]));
		}
		ret = min(ret, tmp);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		++t;
		vector<pair<long long, long long>> points(n);
		for(int i = 0; i < n; ++i){
			cin >> points[i].first >> points[i].second;
		}
		cout << fixed << setprecision(2) << "Case " << t << ": " << max_width(points, n) + 0.004999999999 << '\n';
	}
	return 0;
}
