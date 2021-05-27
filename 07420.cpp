#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#define PI acos(-1)

using namespace std;

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
	return (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
}

void convex_hull(vector<pair<int, int>> &points, vector<pair<int, int>> &hull, int n){
	sort(points.begin(), points.end());
	sort(points.begin() + 1, points.end(), [&](pair<int, int> p1, pair<int, int> p2){
		int cmp = ccw(points[0], p1, p2);
		return cmp > 0 || (cmp == 0 && p1 < p2);
	});
	hull.push_back(points[0]);
	hull.push_back(points[1]);
	for(int i = 2; i < n; ++i){
		while(hull.size() >= 2){
			pair<int, int> b = hull.back();
			hull.pop_back();
			pair<int, int> a = hull.back();
			if(ccw(a, b, points[i]) > 0){
				hull.push_back(b);
				break;
			}
		}
		hull.push_back(points[i]);
	}
}

double dist(pair<int, int> p1, pair<int, int> p2){
	return sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l;
	cin >> n >> l;
	vector<pair<int, int>> points(n);
	for(int i = 0; i < n; ++i){
		cin >> points[i].first >> points[i].second;
	}
	vector<pair<int, int>> hull;
	convex_hull(points, hull, n);
	/*
	for(pair<int, int> p : hull){
		cout << p.first << ' ' << p.second << '\n';
	}
	*/
	unsigned k = hull.size();
	hull.push_back(hull[0]);
	double ans = 2 * PI * l;
	for(unsigned i = 0; i < k; ++i){
		ans += dist(hull[i], hull[i + 1]);
	}
	cout << (int)round(ans);
	return 0;
}
