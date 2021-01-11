#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

bool simulate(vector<tuple<int, int, int>> &shakes, string infect, int n, int p0, int k){
	vector<int> spread(n, 0);
	string state(n, '0');
	spread[p0] = k;
	state[p0] = '1';
	for(tuple<int, int, int> tup : shakes){
		int x = get<1>(tup), y = get<2>(tup);
		if(state[x] == '1' && state[y] == '1'){
			if(spread[x] > 0){
				--spread[x];
			}
			if(spread[y] > 0){
				--spread[y];
			}
		}else if(state[x] == '1' && spread[x] > 0){
			state[y] = '1';
			spread[y] = k;
			--spread[x];
		}else if(state[y] == '1' && spread[y] > 0){
			state[x] = '1';
			spread[x] = k;
			--spread[y];
		}
	}
	return state == infect;
}

tuple<int, int, int> solve(vector<tuple<int, int, int>> &shakes, string infect, int n, int t){
	tuple<int, int, int> ans;
	get<1>(ans) = n;
	vector<bool> patient_zero(n);
	for(int p0 = 0; p0 < n; ++p0){
		for(int k = 0; k <= t; ++k){
			if(simulate(shakes, infect, n, p0, k)){
				patient_zero[p0] = true;
				if(k < get<1>(ans)){
					get<1>(ans) = k;
				}
				if(k > get<2>(ans)){
					get<2>(ans) = k;
				}
			}
		}
	}
	for(int i = 0; i < n; ++i){
		if(patient_zero[i]){
			++get<0>(ans);
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	string infect;
	cin >> infect;
	vector<tuple<int, int, int>> shakes(t);
	for(int i = 0; i < t; ++i){
		int time, x, y;
		cin >> time >> x >> y;
		shakes[i] = make_tuple(time, x - 1, y - 1);
	}
	sort(shakes.begin(), shakes.end());
	tuple<int, int, int> ans = solve(shakes, infect, n, t);
	cout << get<0>(ans) << " " << get<1>(ans) << " ";
	if(get<2>(ans) == t){
		cout << "Infinity";
	}else{
		cout << get<2>(ans);
	}
	return 0;
}
