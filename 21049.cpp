#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<pair<int, int>> pq;
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		if(x > 0){
			pq.push(make_pair(x, i));
		}
	}
	vector<pair<int, int>> ans;
	while(pq.size() > 1){
		pair<int, int> p1 = pq.top();
		pq.pop();
		pair<int, int> p2 = pq.top();
		pq.pop();
		int x = p1.first, i = p1.second, y = p2.first, j = p2.second;
		ans.push_back(make_pair(i, j));
		--x;
		--y;
		if(x > 0){
			pq.push(make_pair(x, i));
		}
		if(y > 0){
			pq.push(make_pair(y, j));
		}
	}
	if(pq.empty()){
		cout << "yes" << '\n';
		for(pair<int, int> p : ans){
			cout << p.first << ' ' << p.second << '\n';
		}
	}else{
		cout << "no";
	}
	return 0;
}
