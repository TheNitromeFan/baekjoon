#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
	return get<1>(a) > get<1>(b) || (get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	vector<tuple<int, int, int>> teams; // team #, solved #, time
	map<tuple<int, int>, int> penalty; // team #, problem #
	map<tuple<int, int>, bool> solved;
	teams.resize(n);
	for(int i = 0; i < n; ++i){
		teams[i] = make_tuple(i + 1, 0, 0);
	}
	for(int j = 0; j < q; ++j){
		int time, team, problem;
		string result;
		cin >> time >> team >> problem >> result;
		if(result == "AC"){
			if(solved.find(make_tuple(team, problem)) != solved.end() && solved[make_tuple(team, problem)]){
				continue;
			}
			++get<1>(teams[team - 1]);
			solved[make_tuple(team, problem)] = true;
			get<2>(teams[team - 1]) += time;
			if(penalty.find(make_tuple(team, problem)) != penalty.end()){
				get<2>(teams[team - 1]) += 20 * penalty[make_tuple(team, problem)];
			}
		}else{
			if(solved.find(make_tuple(team, problem)) != solved.end() && solved[make_tuple(team, problem)]){
				continue;
			}
			solved[make_tuple(team, problem)] = false;
			if(penalty.find(make_tuple(team, problem)) == penalty.end()){
				penalty[make_tuple(team, problem)] = 1;
			}else{
				++penalty[make_tuple(team, problem)];
			}
		}
	}
	stable_sort(teams.begin(), teams.end(), cmp);
	for(auto x : teams){
		cout << get<0>(x) << ' ' << get<1>(x) << ' ' << get<2>(x) << '\n';
	}
	return 0;
}
