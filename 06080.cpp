#include <iostream>
#define MAX 1001

using namespace std;

void traverse(int map[][MAX], bool visited[][MAX], int r, int c, int x, int y, int dx[8], int dy[8]){
	visited[x][y] = true;
	for(int i = 0; i < 8; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] > 0 && !visited[nx][ny]){
			traverse(map, visited, r, c, nx, ny, dx, dy);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c;
	cin >> r >> c;
	int map[MAX][MAX];
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cin >> map[i][j];
		}
	}
	bool visited[MAX][MAX] = {};
	int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
	int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	int islands = 0;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(map[i][j] > 0 && !visited[i][j]){
				++islands;
				traverse(map, visited, r, c, i, j, dx, dy);
			}
		}
	}
	cout << islands;
	return 0;
}
