#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> points(n);
	for(int i = 0; i < n; ++i){
		cin >> points[i];
	}
	sort(points.begin(), points.end());
	vector<pair<int, int>> segments(m);
	vector<int> order(m);
	for(int j = 0; j < m; ++j){
		int start, end;
		cin >> start >> end;
		segments[j] = make_pair(start, end);
		order[j] = j;
	}
	sort(order.begin(), order.end(), [&segments](int a, int b){
		return segments[a] < segments[b];
	});
	vector<int> ans(m);
	int i = 0, j = 0;
	for(int x : order){
		pair<int, int> p = segments[x];
		int start = p.first, end = p.second;
		if(points.front() > end || points.back() < start){
			ans[x] = 0;
			continue;
		}
		j = i;
		while(j < n && points[j] <= end){
			++j;
		}
		while(i < n && points[i] < start){
			++i;
		}
		ans[x] = j - i;
	}
	for(int a : ans){
		cout << a << '\n';
	}
	return 0;
}
