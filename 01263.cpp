#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		int t, s;
		cin >> t >> s;
		v[i] = make_pair(t, s);
	}
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second > b.second;
	});
	int ans = v[0].second;
	for(int i = 0; i < n; ++i){
		ans = min(ans, v[i].second) - v[i].first;
	}
	cout << (ans >= 0 ? ans : -1) << '\n';
	return 0;
}
