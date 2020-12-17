#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

double max_distance(vector<pair<int, int>> &v, int n, int x, int y){
	double ret = 0;
	for(int i = 0; i < n; ++i){
		double dist = sqrt((v[i].first - x) * (v[i].first - x) + (v[i].second - y) * (v[i].second - y));
		if(ret < dist){
			ret = dist;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> h(n);
	for(int i = 0; i < n; ++i){
		cin >> h[i].first >> h[i].second;
	}
	double dist = 1000000000;
	int index = -1;
	for(int i = 0; i < n; ++i){
		double cmp = max_distance(h, n, h[i].first, h[i].second);
		if(dist > cmp){
			dist = cmp;
			index = i;
		}
	}
	cout << h[index].first << ' ' << h[index].second;
	return 0;
}
