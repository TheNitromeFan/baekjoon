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
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; ++i){
		a[i].first = i;
		cin >> a[i].second;
	}
	sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y){
		return x.second < y.second || (x.second == y.second && x.first < y.first);
	});
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans = max(ans, a[i].first - i);
	}
	cout << ans + 1;
	return 0;
}
