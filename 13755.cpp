#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool pane(vector<pair<int, int>> v){
	int area = v[0].first * v[0].second + v[1].first * v[1].second + v[2].first * v[2].second;
	// printf("%d", area);
	int n = (int)sqrt(area);
	if(n * n != area || v[2].first != n){
		return false;
	}
	int m = n - v[2].second;
	// printf("%d\n", m);
	return (v[0].first + v[1].first == n && v[0].second == m && v[1].second == m)
	|| (v[0].first + v[1].second == n && v[0].second == m && v[1].first == m)
	|| (v[0].second + v[1].first == n && v[0].first == m && v[1].second == m)
	|| (v[0].second + v[1].second == n && v[0].first == m && v[1].first == m)
	|| (v[0].first + v[1].first == m && v[0].second == n && v[1].second == n)
	|| (v[0].first + v[1].second == m && v[0].second == n && v[1].first == n)
	|| (v[0].second + v[1].first == m && v[0].first == n && v[1].second == n)
	|| (v[0].second + v[1].second == m && v[0].first == n && v[1].first == n);
}

int main(){
	vector<pair<int, int>> v;
	int x, h;
	for(int i = 0; i < 3; ++i){
		scanf("%d %d", &x, &h);
		if(x < h){
			swap(x, h);
		}
		v.push_back(make_pair(x, h));
	}
	sort(v.begin(), v.end());
	printf("%d", pane(v));
	return 0;
}
