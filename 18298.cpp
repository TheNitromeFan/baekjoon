#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3){
	long long cmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if(cmp > 0){
		return 1;
	}else if(cmp < 0){
		return -1;
	}else{
		return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	double sum = 0;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<pair<long long, long long>> p(n);
		for(int i = 0; i < n; ++i){
			cin >> p[i].first >> p[i].second;
		}
		double area = 0;
		long long x1 = p[0].first, y1 = p[0].second;
		for(int i = 1; i + 1 < n; ++i){
			long long x2 = p[i].first, y2 = p[i].second;
			long long x3 = p[i + 1].first, y3 = p[i + 1].second;
			area += ccw(x1, y1, x2, y2, x3, y3)
			* llabs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2.0;
		}
		sum += abs(area);
	}
	cout << (long long)sum;
	return 0;
}
