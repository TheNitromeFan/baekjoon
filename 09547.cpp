#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

void president(vector<vector<int>> &votes, int c, int v){
	vector<pair<int, int>> tally(c + 1);
	for(int j = 1; j <= c; ++j){
		tally[j].second = j;
	}
	for(int i = 0; i < v; ++i){
		++tally[votes[i][0]].first;
	}
	sort(tally.begin(), tally.end(), greater<pair<int, int>>());
	if(tally[0].first * 2 > v){
		cout << tally[0].second << ' ' << 1 << '\n';
		return;
	}
	int cand1 = tally[0].second, cand2 = tally[1].second;
	int votes1 = 0, votes2 = 0;
	for(int i = 0; i < v; ++i){
		int j = 0;
		while(votes[i][j] != cand1 && votes[i][j] != cand2){
			++j;
		}
		if(votes[i][j] == cand1){
			++votes1;
		}else{
			++votes2;
		}
	}
	if(votes1 > votes2){
		cout << cand1 << ' ' << 2 << '\n';
	}else{
		cout << cand2 << ' ' << 2 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int c, v;
		cin >> c >> v;
		vector<vector<int>> votes(v);
		for(int i = 0; i < v; ++i){
			votes[i].resize(c);
			for(int j = 0; j < c; ++j){
				cin >> votes[i][j];
			}
		}
		president(votes, c, v);
	}
	return 0;
}
