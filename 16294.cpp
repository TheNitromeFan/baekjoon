#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int dx[8] = {-1, 0, 0, 1, -1, 1, -1, 1};
int dy[8] = {0, -1, 1, 0, -1, -1, 1, 1};

int dfs(char hive[][1001], bool visited[][1001], int n, int m, int x, int y){
	visited[x][y] = true;
	int ret = 1;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && hive[nx][ny] == '.' && !visited[nx][ny]){
			ret += dfs(hive, visited, n, m, nx, ny);
		}
	}
	if(x % 2 == 0){
		for(int i = 4; i < 6; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && hive[nx][ny] == '.' && !visited[nx][ny]){
				ret += dfs(hive, visited, n, m, nx, ny);
			}
		}
	}else{
		for(int i = 6; i < 8; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && hive[nx][ny] == '.' && !visited[nx][ny]){
				ret += dfs(hive, visited, n, m, nx, ny);
			}
		}
	}
	return ret;
}

int main(){
	int h, n, m;
	scanf("%d %d %d", &h, &n, &m);
	char hive[1001][1001];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf(" %c", &hive[i][j]);
		}
	}
	bool visited[1001][1001] = {};
	vector<int> cells;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(hive[i][j] == '.' && !visited[i][j]){
				cells.push_back(dfs(hive, visited, n, m, i, j));
			}
		}
	}
	sort(cells.begin(), cells.end(), greater<int>());
	unsigned cnt;
	for(cnt = 0; cnt < cells.size(); ++cnt){
		if(h <= 0){
			break;
		}
		h -= cells[cnt];
	}
	printf("%u", cnt);
	return 0;
}
