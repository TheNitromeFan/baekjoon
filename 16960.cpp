#include <iostream>
#include <vector>

using namespace std;

bool can_ignore(vector<int> &switches, vector<int> &lamps){
	for(int lamp : switches){
		if(lamps[lamp] == 1){
			return false;
		}
	}
	return true;
}

bool any_ignore(vector<vector<int>> &switches, vector<int> &lamps, int n){
	for(int i = 1; i <= n; ++i){
		if(can_ignore(switches[i], lamps)){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> switches(n + 1);
	vector<int> lamps(m + 1);
	for(int i = 1; i <= n; ++i){
		int s;
		cin >> s;
		switches[i].resize(s);
		for(int j = 0; j < s; ++j){
			cin >> switches[i][j];
			++lamps[switches[i][j]];
		}
	}
	cout << any_ignore(switches, lamps, n) << '\n';
	return 0;
}
