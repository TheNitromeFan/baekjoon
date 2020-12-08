#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <cmath>

using namespace std;

double dist(int x1, int y1, int x2, int y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	int x = 0, y = 0;
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
		x += v[i].first;
		y += v[i].second;
	}
	cout << x << ' ' << y << '\n';
	double minDist = 1e6;
	for(int i = 0; i < n; ++i){
		double cmp = dist(v[i].first, v[i].second, x, y);
		if(minDist > cmp){
			minDist = cmp;
		}
	}
	cout << setprecision(2) << fixed << minDist;
	return 0;
}
