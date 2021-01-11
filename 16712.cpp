#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<int> v(n - m + 1);
	for(int j = 0; j < n - m + 1; ++j){
		cin >> v[j];
	}
	vector<int> players;
	for(int i = 0; i < m - 1; ++i){
		players.push_back(a[i]);
	}
	for(int i = m - 1; i < n; ++i){
		players.push_back(a[i]);
		sort(players.begin(), players.end());
		int place = v[i - m + 1] - 1;
		vector<int> w;
		for(int j = 0; j < m; ++j){
			if(j != place){
				w.push_back(players[j]);
			}
		}
		players = w;
	}
	sort(players.begin(), players.end());
	for(int player : players){
		cout << player << ' ';
	}
	return 0;
}
