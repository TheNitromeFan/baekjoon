#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

class Cmp{
	public:
		bool operator()(pair<long long, long long> a, pair<long long, long long> b){
			return a.second > b.second;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<long long, long long>> people(n), stores(m);
	for(int i = 0; i < n; ++i){
		long long li, ri;
		cin >> li >> ri;
		people[i] = make_pair(li, ri);
	}
	for(int j = 0; j < m; ++j){
		long long pj, xj;
		cin >> pj >> xj;
		stores[j] = make_pair(pj, xj);
	}
	sort(people.begin(), people.end());
	sort(stores.begin(), stores.end());
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, Cmp> pq;
	int pos = 0;
	int ans = 0;
	for(int j = 0; j < m; ++j){
		while(pos < n && people[pos].first <= stores[j].first){
			if(people[pos].second >= stores[j].first){
				pq.push(people[pos]);
			}
			++pos;
		}
		while(!pq.empty() && stores[j].second > 0){
			pair<long long, long long> p = pq.top();
			pq.pop();
			if(p.first <= stores[j].first && p.second >= stores[j].first){
				--stores[j].second;
				++ans;
			}
		}
	}
	cout << ans;
	return 0;
}
