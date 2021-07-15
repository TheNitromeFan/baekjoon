#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, n;
	cin >> a >> b >> n;
	priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
	int max_b = -1, max_r = -1;
	for(int i = 0; i < n; ++i){
		int t, m;
		char c;
		cin >> t >> c >> m;
		if(c == 'B'){
			t = max(t, max_b);
			for(int time = t, cnt = 0; cnt < m; time += a, ++cnt){
				pq.push(make_pair(time, c));
			}
			max_b = t + m * a;
		}else{
			t = max(t, max_r);
			for(int time = t, cnt = 0; cnt < m; time += b, ++cnt){
				pq.push(make_pair(time, c));
			}
			max_r = t + m * b;
		}
	}
	vector<int> ans1, ans2;
	int present = 1;
	while(!pq.empty()){
		pair<int, char> p = pq.top();
		pq.pop();
		if(p.second == 'B'){
			ans1.push_back(present);
		}else{
			ans2.push_back(present);
		}
		++present;
	}
	cout << ans1.size() << '\n';
	for(int x : ans1){
		cout << x << ' ';
	}
	cout << '\n';
	cout << ans2.size() << '\n';
	for(int y : ans2){
		cout << y << ' ';
	}
	cout << '\n';
	return 0;
}
