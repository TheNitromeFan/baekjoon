#include <iostream>
#include <cstring>
#include <queue>
#define MAX 401
#define MOD 1000000009

using namespace std;

int bfs(int dist[][MAX], int r, int c){
	int paths[MAX][MAX] = {};
	queue<int> q;
	int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
	int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
	dist[1][1] = 0;
	q.push(1);
	q.push(1);
	paths[1][1] = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 8; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!(nx >= 1 && nx <= r && ny >= 1 && ny <= c)){
				continue;
			}
			if(dist[nx][ny] == -1){
				dist[nx][ny] = dist[x][y] + 1;
				q.push(nx);
				q.push(ny);
				paths[nx][ny] = paths[x][y];
			}else if(dist[nx][ny] == dist[x][y] + 1){
				paths[nx][ny] += paths[x][y];
				paths[nx][ny] %= MOD;
			}
		}
	}
	return paths[r][c];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c;
	cin >> r >> c;
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	int paths = bfs(dist, r, c);
	if(dist[r][c] != -1){
		cout << dist[r][c] << ' ' << paths;
	}else{
		cout << "None";
	}
	return 0;
}
