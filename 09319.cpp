#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

double r(long long x, long long y, long long xi, long long yi, long long si){
	return si / (double)((x - xi) * (x - xi) + (y - yi) * (y - yi));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		double b;
		long long x, y;
		cin >> n >> b >> x >> y;
		vector<pair<double, int>> v(n);
		if(n == 0){
			cout << "NOISE\n";
			continue;
		}
		for(int i = 0; i < n; ++i){
			long long xi, yi, si;
			cin >> xi >> yi >> si;
			v[i] = make_pair(r(x, y, xi, yi, si), i + 1);
		}
		sort(v.begin(), v.end(), greater<pair<double, int>>());
		double sum = 0;
		for(int i = 1; i < n; ++i){
			sum += v[i].first;
		}
		if(v[0].first > 6 * (b + sum)){
			cout << v[0].second << '\n';
		}else{
			cout << "NOISE\n";
		}
	}
	return 0;
}
