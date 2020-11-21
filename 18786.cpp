#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> points(n);
	for(int i = 0; i < n; ++i){
		cin >> points[i].first >> points[i].second;
	}
	int maxArea = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i == j){
				continue;
			}
			for(int k = 0; k < n; ++k){
				if(i == k || j == k){
					continue;
				}
				if(points[i].first == points[j].first && points[i].second == points[k].second){
					int area = abs(points[j].second - points[i].second) * abs(points[k].first - points[i].first);
					if(maxArea < area){
						maxArea = area;
					}
				}
			}
		}
	}
	cout << maxArea;
	return 0;
}
