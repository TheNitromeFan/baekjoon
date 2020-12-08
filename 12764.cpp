#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> cust(n);
	for(int i = 0; i < n; ++i){
		cin >> cust[i].first >> cust[i].second;
	}
	sort(cust.begin(), cust.end());
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	set<int> save;
	int seat = 0;
	int result[100000] = {};
	for(int i = 0; i < n; ++i){
		while(!pq.empty()){
			pair<int, int> pa = pq.top();
			int p = pa.first, q = pa.second;
			if(p <= cust[i].first){
				save.insert(q);
				pq.pop();
			}else{
				break;
			}
		}
		if(save.empty()){
			pq.push(make_pair(cust[i].second, seat));
			++result[seat];
			++seat;
		}else{
			set<int>::iterator it = save.begin();
			pq.push(make_pair(cust[i].second, *it));
			++result[*it];
			save.erase(it);
		}
	}
	cout << seat << '\n';
	for(int i = 0; i < seat; ++i){
		cout << result[i] << ' ';
	}
	return 0;
}
