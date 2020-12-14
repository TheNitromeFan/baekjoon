#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	int cmp = (b.first - a.first) * (c.second - a.second)
				- (c.first - a.first) * (b.second - a.second);
	if(cmp > 0){
		return 1;
	}else if(cmp < 0){
		return -1;
	}else{
		return 0;
	}
}

void get_hull(vector<pair<int, int>> &v, int n, vector<pair<int, int>> &hull){
	sort(v.begin(), v.end());
	sort(v.begin() + 1, v.end(), [&v](pair<int, int> a, pair<int, int> b){
		int cmp = ccw(v[0], a, b);
		return cmp > 0 || (cmp == 0 && a < b);
	});
	hull.push_back(v[0]);
	if(v.size() > 1){
		hull.push_back(v[1]);
	}
	// cout << v[0].first << ' ' << v[0].second << '\n';
	// cout << v[1].first << ' ' << v[1].second << '\n';
	for(int i = 2; i < n; ++i){
		// cout << v[i].first << ' ' << v[i].second << '\n';
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
	/*
	cout << hull.size() << '\n';
	for(unsigned idx = 0; idx < hull.size(); ++idx){
		cout << hull[idx].first << ' ' << hull[idx].second << '\n';
	}
	*/
}

bool disjoint(int a, int b, int c, int d){
	if(a > b){
		swap(a, b);
	}
	if(c > d){
		swap(c, d);
	}
	return b < c || d < a;
}

bool lines_intersect(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d){
	int cmp1 = ccw(a, b, c) * ccw(a, b, d);
	int cmp2 = ccw(c, d, a) * ccw(c, d, b);
	if(cmp1 == 0 && cmp2 == 0){
		return !disjoint(a.first, b.first, c.first, d.first)
				&& !disjoint(a.second, b.second, c.second, d.second);
	}
	return cmp1 <= 0 && cmp2 <= 0;
}

bool point_intersect(vector<pair<int, int>> &v, pair<int, int> p){
	if(v.size() == 1){
		return p == v[0];
	}
	int cnt = 0;
	unsigned n = v.size();
	for(unsigned i = 0; i < n; ++i){
		unsigned j = (i + 1) % n;
		pair<double, double> a = v[i], b = v[j];
		if((a.second > p.second) ^ (b.second > p.second)){
			double x = (b.first - a.first) * (p.second - a.second) / (b.second - a.second) + a.first;
			if(x > p.first){
				++cnt;
			}
		}
	}
	// cout << cnt << '\n';
	return cnt % 2;
}

bool hulls_intersect(vector<pair<int, int>> &hull1, vector<pair<int, int>> &hull2){
	// cout << hull1.size() << ' ' << hull2.size() << '\n';
	for(pair<int, int> x : hull1){
		if(point_intersect(hull2, x)){
			// cout << "yes";
			return true;
		}
	}
	for(pair<int, int> y : hull2){
		if(point_intersect(hull1, y)){
			// cout << "yes";
			return true;
		}
	}
	unsigned n = hull1.size(), m = hull2.size();
	/*
	if(n == 1 || m == 1){
		// cout << "here";
		return false;
	}
	*/
	for(unsigned i = 0; i < n; ++i){
		for(unsigned j = 0; j < m; ++j){
			if(lines_intersect(hull1[i], hull1[(i + 1) % n], hull2[j], hull2[(j + 1) % m])){
				/*
				cout << hull1[i].first << ' ' << hull1[i].second << '\n';
				cout << hull1[(i + 1) % n].first << ' ' << hull1[(i + 1) % n].second << '\n';
				cout << hull2[j].first << ' ' << hull2[j].second << '\n';
				cout << hull2[(j + 1) % m].first << ' ' << hull2[(j + 1) % m].second << '\n';
				*/
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> black(n), white(m);
		for(int i = 0; i < n; ++i){
			cin >> black[i].first >> black[i].second;
		}
		for(int j = 0; j < m; ++j){
			cin >> white[j].first >> white[j].second;
		}
		vector<pair<int, int>> hull_black, hull_white;
		get_hull(black, n, hull_black);
		get_hull(white, m, hull_white);
		cout << (hulls_intersect(hull_black, hull_white) ? "NO" : "YES") << "\n";
	}
	return 0;
}
