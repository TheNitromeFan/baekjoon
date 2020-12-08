#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	int sum = 0, maxX = -1000000, minX = 1000000, maxY = -1000000, minY = 1000000;
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
		if(maxX < v[i].first){
			maxX = v[i].first;
		}
		if(minX > v[i].first){
			minX = v[i].first;
		}
		if(maxY < v[i].second){
			maxY = v[i].second;
		}
		if(minY > v[i].second){
			minY = v[i].second;
		}
	}
	for(int i = 0; i < n; ++i){
		sum += abs(v[i].first - v[(i + 1) % n].first) + abs(v[i].second - v[(i + 1) % n].second);
	}
	cout << sum - 2 * (maxX - minX + maxY - minY);
	return 0;
}
