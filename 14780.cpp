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
		int start, dur;
		cin >> start >> dur;
		v[i] = make_pair(start, start + dur);
	}
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second < b.second;
	});
	int venues = 1;
	int time = v[0].second;
	for(int i = 1; i < n; ++i){
		if(v[i].first >= time){
			++venues;
			time = v[i].second;
		}
	}
	cout << venues;
	return 0;
}
