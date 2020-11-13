#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<unsigned, unsigned> a, pair<unsigned, unsigned> b){
	return a.second > b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, c;
	cin >> r >> c;
	vector<pair<unsigned, unsigned>> places;
	for(int i = 0; i < r; ++i){
		string row;
		cin >> row;
		for(unsigned j = c - 2; j >= 3; --j){
			if(row[j] != '.'){
				places.push_back(make_pair(row[j] - '0', j));
				break;
			}
		}
	}
	sort(places.begin(), places.end(), cmp);
	int place = 1;
	vector<unsigned> ans(10, 0);
	ans[places[0].first] = 1;
	for(unsigned i = 1; i < 9; ++i){
		if(places[i].second < places[i - 1].second){
			++place;
		}
		ans[places[i].first] = place;
	}
	for(unsigned i = 1; i <= 9; ++i){
		cout << ans[i] << '\n';
	}
	return 0;
}
