#include <cstdio>
#include <deque>

using namespace std;

void bfs(int m, int n, int h, int grid[][100][100], deque<int> queue, int value[][100][100]){
	while(!queue.empty()){
		int x = queue[0];
		queue.pop_front();
		int y = queue[0];
		queue.pop_front();
		int z = queue[0];
		queue.pop_front();
		if(x+1 < m && (grid[x+1][y][z] == 0 || (grid[x+1][y][z] == 1 && value[x+1][y][z] > value[x][y][z] + 1))){
			grid[x+1][y][z] = 1;
			value[x+1][y][z] = value[x][y][z] + 1;
			queue.push_back(x+1);
			queue.push_back(y);
			queue.push_back(z);
		}
		if(x-1 >= 0 && (grid[x-1][y][z] == 0 || (grid[x-1][y][z] == 1 && value[x-1][y][z] > value[x][y][z] + 1))){
			grid[x-1][y][z] = 1;
			value[x-1][y][z] = value[x][y][z] + 1;
			queue.push_back(x-1);
			queue.push_back(y);
			queue.push_back(z);
		}
		if(y+1 < n && (grid[x][y+1][z] == 0 || (grid[x][y+1][z] == 1 && value[x][y+1][z] > value[x][y][z] + 1))){
			grid[x][y+1][z] = 1;
			value[x][y+1][z] = value[x][y][z] + 1;
			queue.push_back(x);
			queue.push_back(y+1);
			queue.push_back(z);
		}
		if(y-1 >= 0 && (grid[x][y-1][z] == 0 || (grid[x][y-1][z] == 1 && value[x][y-1][z] > value[x][y][z] + 1))){
			grid[x][y-1][z] = 1;
			value[x][y-1][z] = value[x][y][z] + 1;
			queue.push_back(x);
			queue.push_back(y-1);
			queue.push_back(z);
		}
		if(z+1 < h && (grid[x][y][z+1] == 0 || (grid[x][y][z+1] == 1 && value[x][y][z+1] > value[x][y][z] + 1))){
			grid[x][y][z+1] = 1;
			value[x][y][z+1] = value[x][y][z] + 1;
			queue.push_back(x);
			queue.push_back(y);
			queue.push_back(z+1);
		}
		if(z-1 >= 0 && (grid[x][y][z-1] == 0 || (grid[x][y][z-1] == 1 && value[x][y][z-1] > value[x][y][z] + 1))){
			grid[x][y][z-1] = 1;
			value[x][y][z-1] = value[x][y][z] + 1;
			queue.push_back(x);
			queue.push_back(y);
			queue.push_back(z-1);
		}
	}
}

int max_days(int m, int n, int h, int grid[][100][100], int days[][100][100]){
	int answer = 0;
	for(int k = 0; k < h; ++k){
		for(int j = 0; j < n; ++j){
			for(int i = 0; i < m; ++i){
				if(grid[i][j][k] == 0){
					return -1;
				}else if(grid[i][j][k] == 1 && days[i][j][k] > answer){
					answer = days[i][j][k];
				}
			}
		}
	}
	return answer;
}

int main(){
	int m, n, h;
	scanf("%d %d %d", &m, &n, &h);
	static int grid[100][100][100], days[100][100][100];
	for(int k = 0; k < h; ++k){
		for(int j = 0; j < n; ++j){
			for(int i = 0; i < m; ++i){
				scanf("%d", &grid[i][j][k]);
				days[i][j][k] = 0;
			}
		}
	}
	deque<int> queue;
	for(int k = 0; k < h; ++k){
		for(int j = 0; j < n; ++j){
			for(int i = 0; i < m; ++i){
				if(grid[i][j][k] == 1){
					queue.push_back(i);
					queue.push_back(j);
					queue.push_back(k);
				}
			}
	    }
	}
    bfs(m, n, h, grid, queue, days);
	printf("%d", max_days(m, n, h, grid, days));
	return 0;
}
