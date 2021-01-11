#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>

using namespace std;

int dist(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> p(n + 1);
	for(int i = 1; i <= n; ++i){
		int x, y;
		cin >> x >> y;
		p[i] = make_pair(x, y);
	}
	int base = 0;
	for(int i = 1; i < n; ++i){
		base += dist(p[i].first, p[i].second, p[i + 1].first, p[i + 1].second);
	}
	int ans = base;
	for(int i = 2; i < n; ++i){
		ans = min(ans, base - dist(p[i - 1].first, p[i - 1].second, p[i].first, p[i].second)
				- dist(p[i].first, p[i].second, p[i + 1].first, p[i + 1].second)
				+ dist(p[i - 1].first, p[i - 1].second, p[i + 1].first, p[i + 1].second));
	}
	cout << ans;
	return 0;
}
