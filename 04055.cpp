#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int day = 0;
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		++day;
		vector<pair<int, int>> v(n);
		for(int i = 0; i < n; ++i){
			int start, end;
			cin >> start >> end;
			v[i] = make_pair(2 * start, 2 * end);
		}
		sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
			return a.second - a.first < b.second - b.first;
		});
		int cnt = 0;
		vector<bool> attend(48);
		for(int i = 0; i < n; ++i){
			int start = v[i].first, end = v[i].second;
			for(int time = start; time < end; ++time){
				if(!attend[time]){
					attend[time] = true;
					++cnt;
					break;
				}
			}
		}
		cout << "On day " << day << " Emma can attend as many as " << cnt << " parties.\n";
	}
	return 0;
}
