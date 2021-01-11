#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

void insert_player(vector<vector<pair<int, string>>> &rooms, unsigned cap, int level, string name){
	for(vector<pair<int, string>> &room : rooms){
		if(room.size() < cap && abs(level - room[0].first) <= 10){
			room.push_back(make_pair(level, name));
			return;
		}
	}
	vector<pair<int, string>> new_room;
	new_room.push_back(make_pair(level, name));
	rooms.push_back(new_room);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned p, m;
	cin >> p >> m;
	vector<vector<pair<int, string>>> rooms;
	for(unsigned i = 0; i < p; ++i){
		int level;
		string name;
		cin >> level >> name;
		insert_player(rooms, m, level, name);
	}
	for(vector<pair<int, string>> &room : rooms){
		sort(room.begin(), room.end(), [](pair<int, string> a, pair<int, string> b){
			return a.second < b.second;
		});
		if(room.size() == m){
			cout << "Started!\n";
		}else{
			cout << "Waiting!\n";
		}
		for(pair<int, string> &p : room){
			cout << p.first << " " << p.second << "\n";
		}
	}
	return 0;
}
