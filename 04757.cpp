#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

bool cmp(tuple<string, int, int> a, tuple<string, int, int> b){
	return get<1>(a) > get<1>(b) || (get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b));
}

int main(){
	int n;
	cin >> n;
	vector<tuple<string, int, int>> stats;
	for(int i = 0; i < n; ++i){
		string team;
		cin >> team;
		int solved = 0, penalty = 0;
		for(int problem = 1; problem <= 4; ++problem){
			int sub, time;
			cin >> sub >> time;
			if(time > 0){
				++solved;
				penalty += time + 20 * (sub - 1);
			}
		}
		stats.push_back(make_tuple(team, solved, penalty));
	}
	sort(stats.begin(), stats.end(), cmp);
	tuple<string, int, int> ans = stats[0];
	cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
	return 0;
}
