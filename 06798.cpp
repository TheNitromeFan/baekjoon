#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int hops(int x1, int y1, int x2, int y2){
	queue<int> q;
	int visited[9][9];
	memset(visited, -1, sizeof(visited));
	int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	q.push(x1);
	q.push(y1);
	visited[x1][y1] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == x2 && y == y2){
			return visited[x2][y2];
		}
		for(int i = 0; i < 8; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && visited[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << hops(x1, y1, x2, y2);
	return 0;
}
