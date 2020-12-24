#include <iostream>
#define MAX 41

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c;
	cin >> r >> c;
	int papaya[MAX][MAX];
	for(int i = 1; i <= r; ++i){
		for(int j = 1; j <= c; ++j){
			cin >> papaya[i][j];
		}
	}
	int x = 1, y = 1;
	int eaten = papaya[1][1];
	bool visited[MAX][MAX] = {};
	visited[1][1] = true;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	while(!(x == r && y == c)){
		int dir = -1, max = 0;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 1 && nx <= r && ny >= 1 && ny <= c && !visited[nx][ny] && max < papaya[nx][ny]){
				dir = i;
				max = papaya[nx][ny];
			}
		}
		x += dx[dir];
		y += dy[dir];
		eaten += papaya[x][y];
		visited[x][y] = true;
	}
	cout << eaten;
	return 0;
}
