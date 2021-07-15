#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>

using namespace std;

int dist(tuple<int, int> a, tuple<int, int> b){
	int x1 = get<0>(a), y1 = get<1>(a), x2 = get<0>(b), y2 = get<1>(b);
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

double sum_of_dists(vector<tuple<int, int>> &a, vector<tuple<int, int>> &b, int n, int m){
	vector<tuple<int, int, int>> v;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			v.push_back(make_tuple(dist(a[i], b[j]), i, j));
		}
	}
	sort(v.begin(), v.end());
	vector<bool> assigned_a(n), assigned_b(m);
	double ret = 0;
	for(tuple<int, int, int> t : v){
		int d = get<0>(t), i = get<1>(t), j = get<2>(t);
		if(!assigned_a[i] && !assigned_b[j]){
			ret += sqrt(d);
			assigned_a[i] = true;
			assigned_b[j] = true;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, p;
	cin >> n >> m >> p;
	vector<tuple<int, int>> judge(n), tar(m), feather(p);
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		judge[i] = make_tuple(x, y);
	}
	for(int j = 0; j < m; ++j){
		int x, y;
		cin >> x >> y;
		tar[j] = make_tuple(x, y);
	}
	for(int k = 0; k < p; ++k){
		int x, y;
		cin >> x >> y;
		feather[k] = make_tuple(x, y);
	}
	cout << fixed << setprecision(12) << sum_of_dists(judge, tar, n, m) + sum_of_dists(judge, feather, n, p) << '\n';
	return 0;
}
