#include <iostream>
#include <queue>
#define MAX 11

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int r, c, a, b;
		cin >> r >> c >> a >> b;
		int map[MAX][MAX];
		for(int i = 1; i <= r; ++i){
			for(int j = 1; j <= c; ++j){
				cin >> map[i][j];
			}
		}
		queue<int> q;
		bool visited[MAX][MAX] = {};
		int dx[4] = {1, -1, 0, 0};
		int dy[4] = {0, 0, 1, -1};
		q.push(a);
		q.push(b);
		visited[a][b] = true;
		while(!q.empty()){
			int x = q.front();
			q.pop();
			int y = q.front();
			q.pop();
			for(int i = 0; i < 4; ++i){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx >= 1 && nx <= r && ny >= 1 && ny <= c && map[nx][ny] >= map[x][y] && !visited[nx][ny]){
					q.push(nx);
					q.push(ny);
					visited[nx][ny] = true;
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= r; ++i){
			for(int j = 1; j <= c; ++j){
				if((i == 1 || i == r || j == 1 || j == c) && visited[i][j]){
					++ans;
				}
			}
		}
		cout << "Case #" << a0 << ": " << ans << "\n";
	}
	return 0;
}
