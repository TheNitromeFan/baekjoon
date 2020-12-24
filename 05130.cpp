#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
	return (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i].first >> v[i].second;
		}
		int area = 0;
		for(int i = 2; i < n; ++i){
			area += ccw(v[0], v[i - 1], v[i]);
		}
		cout << "Data Set " << a0 << ":\n" << (area > 0 ? "LEFT" : "RIGHT") << "\n\n";
	}
	return 0;
}
