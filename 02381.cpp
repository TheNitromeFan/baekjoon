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
	vector<pair<int, int>> p(n);
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		p[i] = make_pair(x, y);
	}
	sort(p.begin(), p.end(), [](pair<int, int> p1, pair<int, int> p2){
		int x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second;
		return x1 + y1 < x2 + y2;
	});
	int cand1 = p[n - 1].first + p[n - 1].second - p[0].first - p[0].second;
	sort(p.begin(), p.end(), [](pair<int, int> p1, pair<int, int> p2){
		int x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second;
		return x1 - y1 < x2 - y2;
	});
	int cand2 = p[n - 1].first - p[n - 1].second - p[0].first + p[0].second;
	cout << max(cand1, cand2);
	return 0;
}
