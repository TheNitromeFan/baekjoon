#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> players(n);
	for(int i = 0; i < n; ++i){
		cin >> players[i];
	}
	unordered_map<string, bool> out;
	for(string player : players){
		out[player] = false;
	}
	vector<string> initial = players;
	int r;
	cin >> r;
	for(int j = 0; j < r; ++j){
		int s, m;
		cin >> s >> m;
		--s;
		m %= n;
		for(int i = 0; i < m; ++i){
			string name = players.back();
			players.pop_back();
			players.insert(players.begin(), name);
		}
		cout << players[s] << " has been eliminated.\n";
		out[players[s]] = true;
		players.erase(players.begin() + s);
		--n;
	}
	if(n == 1){
		cout << players[0] << " has won.\n";
	}else{
		cout << "Players left are";
		for(string &player : initial){
			if(!out[player]){
				cout << ' ' << player;
			}
		}
		cout << ".\n";
	}
	return 0;
}
