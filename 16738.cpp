#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#define MAX 5001

using namespace std;

int find_empty_rooms(bool rooms[MAX], int n, int y){
	int start = 1;
	while(start <= n){
		int idx = start;
		while(idx <= n && !rooms[idx] && idx - start + 1 < y){
			++idx;
		}
		if(idx <= n && !rooms[idx] && idx - start + 1 == y){
			return start;
		}
		start = idx + 1;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	bool rooms[MAX] = {};
	vector<tuple<int, int, int>> party = {make_tuple(0, 0, 0)};
	for(int a0 = 0; a0 < q; ++a0){
		string s;
		cin >> s;
		if(s == "new"){
			int x, y;
			cin >> x >> y;
			int room_start = find_empty_rooms(rooms, n, y);
			if(room_start == -1){
				cout << "REJECTED\n";
				continue;
			}
			int room_end = room_start + y - 1;
			cout << room_start << ' ' << room_end << '\n';
			for(int room = room_start; room <= room_end; ++room){
				rooms[room] = true;
			}
			party.push_back(make_tuple(room_start, room_end, x));
		}else if(s == "in"){
			int a, b;
			cin >> a >> b;
			get<2>(party[a]) += b;
		}else{
			int a, b;
			cin >> a >> b;
			get<2>(party[a]) -= b;
			if(get<2>(party[a]) == 0){
				int room_start = get<0>(party[a]), room_end = get<1>(party[a]);
				cout << "CLEAN " << room_start << ' ' << room_end << '\n';
				for(int room = room_start; room <= room_end; ++room){
					rooms[room] = false;
				}
			}
		}
	}
	return 0;
}
