#include <cstdio>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(tuple<int, int, int, int> a, tuple<int, int, int, int> b){
	return get<1>(a) > get<1>(b) || (get<1>(a) == get<1>(b) && (get<2>(a) < get<2>(b) || (get<2>(a) == get<2>(b) && get<3>(a) < get<3>(b))));
}

int main(){
	int tc;
	scanf("%d", &tc);
	for(int a0 = 0; a0 < tc; ++a0){
		int n, k, t, m;
		scanf("%d %d %d %d", &n, &k, &t, &m);
		vector<tuple<int, int, int, int>> teams(n + 1, make_tuple(0, 0, 0, 0)); // team no., points, submissions, last submit
		for(int i = 1; i <= n; ++i){
			get<0>(teams[i]) = i;
		}
		map<tuple<int, int>, int> sub; // team no., problem no., score
		for(int j = 0; j < m; ++j){
			int team, problem, score;
			scanf("%d %d %d", &team, &problem, &score);
			++get<2>(teams[team]);
			get<3>(teams[team]) = j;
			if(sub.find(make_tuple(team, problem)) == sub.end()){
				get<1>(teams[team]) += score;
				sub[make_tuple(team, problem)] = score;
			}else if(sub[make_tuple(team, problem)] < score){
				get<1>(teams[team]) += score - sub[make_tuple(team, problem)];
				sub[make_tuple(team, problem)] = score;
			}
		}
		sort(teams.begin(), teams.end(), cmp);
		int rank = 1;
		for(int i = 0; i < n; ++i){
			if(get<0>(teams[i]) == t){
				printf("%d\n", rank);
				break;
			}
			++rank;
		}
	}
	return 0;
}
