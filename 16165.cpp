#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	map<string, vector<string>> members;
	map<string, string> is_member_of;
	for(int i = 0; i < n; ++i){
		string group;
		int member_cnt;
		cin >> group >> member_cnt;
		members[group].resize(member_cnt);
		for(int j = 0; j < member_cnt; ++j){
			cin >> members[group][j];
			is_member_of[members[group][j]] = group;
		}
		sort(members[group].begin(), members[group].end());
	}
	for(int q = 0; q < m; ++q){
		string s;
		int type;
		cin >> s >> type;
		if(type){
			cout << is_member_of[s] << '\n';
		}else{
			for(string member : members[s]){
				cout << member << '\n';
			}
		}
	}
	return 0;
}
