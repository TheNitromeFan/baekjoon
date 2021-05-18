#include <iostream>
#define MAX 100

using namespace std;

int paths(bool visited[][MAX], int x, int y, int n, int dx[][3], int dy[][3], int last){
	if(visited[x][y] && n == 0){
		return 1;
	}else if(visited[x][y] || n == 0){
		return 0;
	}
	int ret = 0;
	visited[x][y] = true;
	for(int i = 0; i < 3; ++i){
		if(i == last){
			continue;
		}
		int nx = x + dx[n % 2][i], ny = y + dy[n % 2][i];
		ret += paths(visited, nx, ny, n - 1, dx, dy, i);
	}
	visited[x][y] = false;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int dx[2][3] = {{1, 0, -1}, {-1, 0, 1}};
	int dy[2][3] = {{-1, 1, -1}, {1, -1, 1}};
	bool visited[MAX][MAX] = {};
	cout << paths(visited, 50, 50, n + 1, dx, dy, -1) / 3;
	return 0;
}
