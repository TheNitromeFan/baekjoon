#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool adjacent(bool s[][5], int startx, int starty){
	queue<int> q;
	q.push(startx);
	q.push(starty);
	bool visited[5][5] = {};
	visited[startx][starty] = true;
	int cnt = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && s[nx][ny] && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
				++cnt;
			}
		}
	}
	return cnt == 7;
}

bool majority(char map[][6], bool s[][5]){
	int cnt = 0;
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			if(s[i][j] && map[i][j] == 'S'){
				++cnt;
			}
		}
	}
	return cnt >= 4;
}

int main(){
	char map[5][6];
	for(int i = 0; i < 5; ++i){
		scanf("%s", map[i]);
	}
	string bitmask(7, 1);
	bitmask.resize(25, 0);
	int cnt = 0;
	do{
		bool selected[5][5] = {};
		int x = 0, y = 0;
		for(int i = 0; i < 25; ++i){
			if(bitmask[i]){
				x = i / 5;
				y = i % 5;
				selected[x][y] = true;
			}
		}
		if(adjacent(selected, x, y) && majority(map, selected)){
			++cnt;
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	printf("%d", cnt);
	return 0;
}
