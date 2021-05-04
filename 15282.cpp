#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n, m;
	cin >> n >> m;
	vector<int> tasks(n), intervals(m);
	for(unsigned i = 0; i < n; ++i){
		cin >> tasks[i];
	}
	for(unsigned j = 0; j < m; ++j){
		cin >> intervals[j];
	}
	sort(tasks.begin(), tasks.end(), greater<int>());
	sort(intervals.begin(), intervals.end(), greater<int>());
	unsigned i = 0, j = 0;
	int cnt = 0;
	while(i < n && j < m){
		if(tasks[i] <= intervals[j]){
			++cnt;
			++i;
			++j;
		}else{
			++i;
		}
	}
	cout << cnt;
	return 0;
}
