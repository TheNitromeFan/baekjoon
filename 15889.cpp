#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> throws(n);
	for(int i = 0; i < n; ++i){
		cin >> throws[i].first;
	}
	for(int i = 0; i < n - 1; ++i){
		cin >> throws[i].second;
	}
	sort(throws.begin(), throws.end());
	int idx = 0;
	int maxDistance = throws[0].second;
	while(idx < n - 1){
		++idx;
		if(throws[idx].first > maxDistance){
			cout << "엄마 나 전역 늦어질 것 같아";
			return 0;
		}
		maxDistance = max(maxDistance, throws[idx].first + throws[idx].second);
	}
	cout << "권병장님, 중대장님이 찾으십니다";
	return 0;
}
