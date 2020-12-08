#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<double, int>> v(n);
	for(int i = 0; i < n; ++i){
		int xi, yi, vi;
		cin >> xi >> yi >> vi;
		v[i].first = sqrt(xi * xi + yi * yi) / vi;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
	for(pair<double, int> p : v){
		cout << p.second << "\n";
	}
	return 0;
}
