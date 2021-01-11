#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

bool twin(vector<tuple<int, int, int, int, int, int>> &snow, int n){
	set<tuple<int, int, int, int, int, int>> s;
	for(int i = 0; i < n; ++i){
		vector<tuple<int, int, int, int, int, int>> comb(12);
		comb[0] = snow[i];
		for(int j = 1; j < 6; ++j){
			tuple<int, int, int, int, int, int> t = comb[j - 1];
			comb[j] = make_tuple(get<1>(t), get<2>(t), get<3>(t), get<4>(t), get<5>(t), get<0>(t));
		}
		tuple<int, int, int, int, int, int> u = comb[0];
		comb[6] = make_tuple(get<0>(u), get<5>(u), get<4>(u), get<3>(u), get<2>(u), get<1>(u));
		for(int j = 7; j < 12; ++j){
			tuple<int, int, int, int, int, int> t = comb[j - 1];
			comb[j] = make_tuple(get<1>(t), get<2>(t), get<3>(t), get<4>(t), get<5>(t), get<0>(t));
		}
		tuple<int, int, int, int, int, int> cand = comb[0];
		for(int j = 1; j < 12; ++j){
			cand = min(cand, comb[j]);
		}
		if(s.find(cand) != s.end()){
			return true;
		}
		s.insert(cand);
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int, int, int, int, int, int>> snow(n);
	for(int i = 0; i < n; ++i){
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		snow[i] = make_tuple(a, b, c, d, e, f);
	}
	cout << (twin(snow, n) ? "Twin snowflakes found." : "No two snowflakes are alike.");
	return 0;
}
