#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> votes(m);
	for(int j = 0; j < m; ++j){
		votes[j].first = j + 1;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int vote;
			cin >> vote;
			votes[j].second += vote;
		}
	}
	sort(votes.begin(), votes.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second > b.second || (a.second == b.second && a.first < b.first);
	});
	for(pair<int, int> &p : votes){
		cout << p.first << ' ';
	}
	return 0;
}
