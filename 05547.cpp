#include <iostream>
#include <queue>
#define MAX 150

using namespace std;

int lights(int map[MAX][MAX], int startx, int starty){
	queue<int> q;
	bool visited[MAX][MAX] = {};
	int dx[8] = {1, 0, 0, -1, 1, -1, 1, -1};
	int dy[8] = {0, 1, -1, 0, -1, -1, 1, 1};
	q.push(startx);
	q.push(starty);
	visited[startx][starty] = true;
	int ret = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(!(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX)){
				continue;
			}
			if(map[nx][ny] == 0 && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}else if(map[nx][ny] == 1){
				++ret;
			}
		}
		if(x % 2 == 0){
			for(int i = 4; i < 6; ++i){
				int nx = x + dx[i], ny = y + dy[i];
				if(!(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX)){
					continue;
				}
				if(map[nx][ny] == 0 && !visited[nx][ny]){
					q.push(nx);
					q.push(ny);
					visited[nx][ny] = true;
				}else if(map[nx][ny] == 1){
					++ret;
				}
			}
		}else{
			for(int i = 6; i < 8; ++i){
				int nx = x + dx[i], ny = y + dy[i];
				if(!(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX)){
					continue;
				}
				if(map[nx][ny] == 0 && !visited[nx][ny]){
					q.push(nx);
					q.push(ny);
					visited[nx][ny] = true;
				}else if(map[nx][ny] == 1){
					++ret;
				}
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h;
	cin >> w >> h;
	int map[MAX][MAX] = {};
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= w; ++j){
			cin >> map[i][j];
		}
	}
	cout << lights(map, 120, 120);
	return 0;
}
