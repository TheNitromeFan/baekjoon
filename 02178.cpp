#include <cstdio>
#include <deque>

using namespace std;

int bfs(int n, int m, int grid[][100], int start_x, int start_y, int value[][100]){
	deque<int> queue;
	bool visited[100][100];
	for(int j = 0; j < n; ++j){
		for(int i = 0; i < m; ++i){
			visited[i][j] = false;
		}
	}
	queue.push_back(start_x);
	queue.push_back(start_y);
	visited[start_x][start_y] = true;
	while(!queue.empty()){
		int x = queue[0];
		queue.pop_front();
		int y = queue[0];
		queue.pop_front();
		if(x+1 < m && grid[x+1][y] == 1 && !visited[x+1][y]){
			value[x+1][y] = value[x][y] + 1;
			queue.push_back(x+1);
			queue.push_back(y);
			visited[x+1][y] = true;
		}
		if(x-1 >= 0 && grid[x-1][y] == 1 && !visited[x-1][y]){
			value[x-1][y] = value[x][y] + 1;
			queue.push_back(x-1);
			queue.push_back(y);
			visited[x-1][y] = true;
		}
		if(y+1 < n && grid[x][y+1] == 1 && !visited[x][y+1]){
			value[x][y+1] = value[x][y] + 1;
			queue.push_back(x);
			queue.push_back(y+1);
			visited[x][y+1] = true;
		}
		if(y-1 >= 0 && grid[x][y-1] == 1 && !visited[x][y-1]){
			value[x][y-1] = value[x][y] + 1;
			queue.push_back(x);
			queue.push_back(y-1);
			visited[x][y-1] = true;
		}
	}
	return value[m-1][n-1];
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int grid[100][100], steps[100][100];
	for(int j = 0; j < n; ++j){
		char s[101];
		scanf("%s", s);
		for(int i = 0; i < m; ++i){
			grid[i][j] = s[i] - '0';
			steps[i][j] = 1;
		}
	}
	printf("%d", bfs(n, m, grid, 0, 0, steps));
	return 0;
}
