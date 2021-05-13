#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<long long, int>> px(n + 1), py(n + 1);
	for(int i = 1; i <= n; ++i){
		int x, y;
		cin >> x >> y;
		px[i] = make_pair(x, i);
		py[i] = make_pair(y, i);
	}
	sort(px.begin() + 1, px.end());
	sort(py.begin() + 1, py.end());
	vector<int> x_index(n + 1), y_index(n + 1);
	for(int i = 1; i <= n; ++i){
		x_index[px[i].second] = i;
		y_index[py[i].second] = i;
	}
	/*
	for(int i = 1; i <= n; ++i){
		cout << x_index[i] << ' ' << y_index[i] << '\n';
	}
	*/
	vector<long long> x_psum(n + 1), y_psum(n + 1);
	for(int i = 1; i <= n; ++i){
		x_psum[i] = x_psum[i - 1] + px[i].first;
		y_psum[i] = y_psum[i - 1] + py[i].first;
	}
	int point = 0;
	long long dist = numeric_limits<long long>::max();
	for(int i = 1; i <= n; ++i){
		int xi = x_index[i], yi = y_index[i];
		long long cmp = (xi - 1) * px[xi].first - x_psum[xi - 1] + x_psum[n] - x_psum[xi] - (n - xi) * px[xi].first
		+ (yi - 1) * py[yi].first - y_psum[yi - 1] + y_psum[n] - y_psum[yi] - (n - yi) * py[yi].first;
		if(cmp < dist){
			point = i;
			dist = cmp;
		}
	}
	cout << point;
	return 0;
}
