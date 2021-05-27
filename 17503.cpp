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
	unsigned n, k;
	long long m;
	cin >> n >> m >> k;
	vector<pair<int, int>> beers(k);
	for(unsigned i = 0; i < k; ++i){
		cin >> beers[i].first >> beers[i].second;
	}
	sort(beers.begin(), beers.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second < b.second || (a.second == b.second && a.first < b.first);
	});
	priority_queue<int, vector<int>, greater<int>> pq;
	long long favor = 0;
	for(unsigned i = 0; i < k; ++i){
		pq.push(beers[i].first);
		favor += beers[i].first;
		if(pq.size() > n){
			int x = pq.top();
			pq.pop();
			favor -= x;
		}
		if(pq.size() == n && favor >= m){
			cout << beers[i].second;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
