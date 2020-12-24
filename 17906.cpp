#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> fish(n);
	for(int i = 0; i < n; ++i){
		cin >> fish[i];
	}
	vector<pair<int, int>> monger(m);
	for(int j = 0; j < m; ++j){
		cin >> monger[j].first >> monger[j].second;
	}
	sort(fish.begin(), fish.end(), greater<int>());
	sort(monger.begin(), monger.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second > b.second;
	});
	int j = 0;
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		ans += (long long)fish[i] * monger[j].second;
		--monger[j].first;
		if(monger[j].first == 0){
			++j;
			if(j == m){
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
