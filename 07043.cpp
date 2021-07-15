#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	int furthest = 0;
	int time = 1;
	while(time <= t){
		for(int i = 0; i < n; ++i){
			if(v[i].first <= time && v[i].second > furthest){
				furthest = v[i].second;
			}
		}
		if(furthest >= time){
			time = furthest + 1;
			++cnt;
		}else{
			break;
		}
	}
	cout << (time == t + 1 ? cnt : -1) << '\n';
	return 0;
}
