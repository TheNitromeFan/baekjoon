#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

long long ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3){
	return (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
}

long long dist(pair<long long, long long> p1, pair<long long, long long> p2){
	return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);
}

void convex_hull(vector<pair<long long, long long>> &points, vector<pair<long long, long long>> &hull, int n){
	sort(points.begin(), points.end());
	sort(points.begin() + 1, points.end(), [&](pair<long long, long long> p1, pair<long long, long long> p2){
		long long cmp = ccw(points[0], p1, p2);
		return cmp > 0 || (cmp == 0 && dist(points[0], p1) < dist(points[0], p2));
	});
	hull.push_back(points[0]);
	hull.push_back(points[1]);
	for(int i = 2; i < n; ++i){
		while(hull.size() >= 2){
			pair<long long, long long> b = hull.back();
			hull.pop_back();
			pair<long long, long long> a = hull.back();
			if(ccw(a, b, points[i]) > 0){
				hull.push_back(b);
				break;
			}
		}
		hull.push_back(points[i]);
	}
}

void rotating_calipers(vector<pair<long long, long long>> hull, unsigned &idx1, unsigned &idx2){
	long long max_dist = 0;
	unsigned pt = 0;
	unsigned n = hull.size();
	/*
	for(pair<long long, long long> p : hull){
		cout << p.first << ' ' << p.second << '\n';
	}
	*/
	hull.push_back(hull[0]);
	for(unsigned i = 0; i < n; ++i){
		long long d = 0;
		while(pt < n){
			long long tmp = ccw(make_pair(0LL, 0LL),
			make_pair(hull[i + 1].first - hull[i].first, hull[i + 1].second - hull[i].second),
			make_pair(hull[pt + 1].first - hull[pt].first, hull[pt + 1].second - hull[pt].second));
			if(tmp < 0){
				break;
			}
			d = dist(hull[i], hull[pt]);
			if(d > max_dist){
				max_dist = d;
				idx1 = i;
				idx2 = pt;
			}
			++pt;
		}
		d = dist(hull[i], hull[pt]);
		if(d > max_dist){
			max_dist = d;
			idx1 = i;
			idx2 = pt;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<pair<long long, long long>> points(n);
		for(int i = 0; i < n; ++i){
			cin >> points[i].first >> points[i].second;
		}
		vector<pair<long long, long long>> hull;
		convex_hull(points, hull, n);
		unsigned idx1 = 0, idx2 = 0;
		rotating_calipers(hull, idx1, idx2);
		cout << hull[idx1].first << ' ' << hull[idx1].second << ' ' << hull[idx2].first << ' ' << hull[idx2].second << '\n';
	}
	return 0;
}
