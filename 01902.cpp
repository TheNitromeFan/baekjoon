#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

double height(vector<pair<int, int>> &v, int n, double x){
	double ret = 0;
	for(int i = 0; i + 1 < n; ++i){
		double x1 = v[i].first, y1 = v[i].second, x2 = v[i + 1].first, y2 = v[i + 1].second;
		ret = max(ret, (y2 - y1) / (x2 - x1) * (x - x1) + y1);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	double low = v[0].first, high = v[n - 1].first;
	for(int j = 0; j < 100; ++j){
		double mid1 = (2 * low + high) / 3;
		double mid2 = (low + 2 * high) / 3;
		if(height(v, n, mid1) > height(v, n, mid2)){
			low = mid1;
		}else{
			high = mid2;
		}
	}
	cout << fixed << setprecision(2) << height(v, n, low);
	return 0;
}
