#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, g;
	cin >> n >> m >> g;
	map<string, char> players;
	string player;
	for(int i = 0; i < n; ++i){
		cin >> player;
		players[player] = 'A';
	}
	for(int j = 0; j < m; ++j){
		cin >> player;
		players[player] = 'B';
	}
	int a = 0, b = 0;
	for(int k = 0; k < g; ++k){
		cin >> player;
		if(players[player] == 'A'){
			++a;
		}else{
			++b;
		}
	}
	if(a > b){
		cout << 'A';
	}else if(a < b){
		cout << 'B';
	}else{
		cout << "TIE";
	}
	return 0;
}
