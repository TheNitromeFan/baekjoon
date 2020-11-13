#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool all_visited(vector<bool> &v){
	for(auto x : v){
		if(!x){
			return false;
		}
	}
	return true;
}

int main(){
	string turns;
	cin >> turns;
	int ans = 0;
	int dir = 0;
	bool streak = false;
	vector<bool> visited(4, false);
	unsigned idx;
	for(idx = 0; idx < turns.length(); ++idx){
		if(dir == 0){
			if(streak && all_visited(visited) && turns[idx - 1] == 'R'){
				++ans;
			}
			streak = false;
			fill(visited.begin(), visited.end(), false);
			if(turns[idx] == 'R'){
				streak = true;
			}
		}
		if(turns[idx] == 'R'){
			dir = (dir + 1) % 4;
		}else{
			dir = (dir + 3) % 4;
		}
		visited[dir] = true;
	}
	if(dir == 0 && streak && all_visited(visited) && turns[idx - 1] == 'R'){
		++ans;
	}
	cout << ans;
	return 0;
}
