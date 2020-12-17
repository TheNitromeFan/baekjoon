#include <iostream>
#include <string>
#include <queue>
#define MAX 5000

using namespace std;

void visit(bool map[][MAX], bool visited[][MAX], int sx, int sy){
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	queue<int> q;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && !map[nx][ny] && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
}

int regions(bool map[][MAX]){
	bool visited[MAX][MAX] = {};
	int ret = 0;
	for(int i = 0; i < MAX; ++i){
		for(int j = 0; j < MAX; ++j){
			if(!map[i][j] && !visited[i][j]){
				visit(map, visited, i, j);
				++ret;
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool map[MAX][MAX] = {};
	int x = 2500, y = 2500;
	map[x][y] = true;
	int n;
	cin >> n;
	string path;
	cin >> path;
	for(char c : path){
		switch(c){
			case 'N':
				++y;
				map[x][y] = true;
				++y;
				map[x][y] = true;
				break;
			case 'S':
				--y;
				map[x][y] = true;
				--y;
				map[x][y] = true;
				break;
			case 'E':
				++x;
				map[x][y] = true;
				++x;
				map[x][y] = true;
				break;
			case 'W':
				--x;
				map[x][y] = true;
				--x;
				map[x][y] = true;
				break;
		}
	}
	cout << regions(map) - 1;
	return 0;
}
