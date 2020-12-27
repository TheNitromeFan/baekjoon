#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		v[i] = make_pair(x, y);
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	for(int i = 0; i < n; i += 2){
		ans += abs(v[i].second - v[i + 1].second);
	}
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second < b.second || (a.second == b.second && a.first < b.first);
	});
	for(int i = 0; i < n; i += 2){
		ans += abs(v[i].first - v[i + 1].first);
	}
	cout << ans;
	return 0;
}
