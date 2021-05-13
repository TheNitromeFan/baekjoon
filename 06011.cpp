#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second < b.second;
	});
	int end = v[0].second;
	int cnt = 1;
	for(int i = 1; i < n; ++i){
		if(v[i].first >= end){
			end = v[i].second;
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
