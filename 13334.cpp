#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
		if(v[i].first > v[i].second){
			swap(v[i].first, v[i].second);
		}
	}
	int len;
	cin >> len;
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second < b.second
		|| (a.second == b.second && a.first < b.first);
	});
	priority_queue<int, vector<int>, greater<int>> pq;
	priority_queue<int, vector<int>, greater<int>>::size_type ans = 0;
	for(pair<int, int> p : v){
		if(p.second - p.first > len){
			continue;
		}
		pq.push(p.first);
		while(!pq.empty() && p.second - pq.top() > len){
			pq.pop();
		}
		ans = max(ans, pq.size());
	}
	cout << ans;
	return 0;
}
