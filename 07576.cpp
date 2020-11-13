#include <cstdio>
#include <deque>

using namespace std;

void bfs(int m, int n, int grid[][1000], deque<int> queue, int value[][1000]){
	while(!queue.empty()){
		int x = queue[0];
		queue.pop_front();
		int y = queue[0];
		queue.pop_front();
		if(x+1 < m && (grid[x+1][y] == 0 || (grid[x+1][y] == 1 && value[x+1][y] > value[x][y] + 1))){
			grid[x+1][y] = 1;
			value[x+1][y] = value[x][y] + 1;
			queue.push_back(x+1);
			queue.push_back(y);
		}
		if(x-1 >= 0 && (grid[x-1][y] == 0 || (grid[x-1][y] == 1 && value[x-1][y] > value[x][y] + 1))){
			grid[x-1][y] = 1;
			value[x-1][y] = value[x][y] + 1;
			queue.push_back(x-1);
			queue.push_back(y);
		}
		if(y+1 < n && (grid[x][y+1] == 0 || (grid[x][y+1] == 1 && value[x][y+1] > value[x][y] + 1))){
			grid[x][y+1] = 1;
			value[x][y+1] = value[x][y] + 1;
			queue.push_back(x);
			queue.push_back(y+1);
		}
		if(y-1 >= 0 && (grid[x][y-1] == 0 || (grid[x][y-1] == 1 && value[x][y-1] > value[x][y] + 1))){
			grid[x][y-1] = 1;
			value[x][y-1] = value[x][y] + 1;
			queue.push_back(x);
			queue.push_back(y-1);
		}
	}
}

int max_days(int m, int n, int grid[][1000], int days[][1000]){
	int answer = 0;
	for(int j = 0; j < n; ++j){
		for(int i = 0; i < m; ++i){
			if(grid[i][j] == 0){
				return -1;
			}else if(grid[i][j] == 1 && days[i][j] > answer){
				answer = days[i][j];
			}
		}
	}
	return answer;
}

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	static int grid[1000][1000], days[1000][1000];
	for(int j = 0; j < n; ++j){
		for(int i = 0; i < m; ++i){
			scanf("%d", &grid[i][j]);
			days[i][j] = 0;
		}
	}
	deque<int> queue;
	for(int j = 0; j < n; ++j){
		for(int i = 0; i < m; ++i){
			if(grid[i][j] == 1){
				queue.push_back(i);
				queue.push_back(j);
			}
		}
    }
    bfs(m, n, grid, queue, days);
	printf("%d", max_days(m, n, grid, days));
	return 0;
}
