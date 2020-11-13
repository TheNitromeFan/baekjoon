#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 50

using namespace std;

int bfs(queue<int> &q, int grid[][MAX], int visited[MAX][MAX], int n){
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	int ans;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		ans = visited[x][y] - 1;
		for(int ind = 0; ind < 4; ++ind){
			int nx = x + dx[ind], ny = y + dy[ind];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n
			&& grid[nx][ny] != 1 && visited[nx][ny] == 0){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
	/*
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(grid[i][j] != 1 && visited[i][j] == 0){
				return -1;
			}
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int lab[MAX][MAX];
	vector<int> spaces;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> lab[i][j];
			if(lab[i][j] == 2){
				lab[i][j] = 0;
				spaces.push_back(i);
				spaces.push_back(j);
			}
		}
	}
	int lab_copy[MAX][MAX];
	string bitmask(m, 1);
	bitmask.resize(spaces.size() / 2, 0);
	int min_time = MAX * MAX;
	do{
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				lab_copy[i][j] = lab[i][j];
			}
		}
		queue<int> q;
		int visited[MAX][MAX] = {};
		for(unsigned ind = 0; ind < spaces.size() / 2; ++ind){
			if(bitmask[ind]){
				q.push(spaces[2 * ind]);
				q.push(spaces[2 * ind + 1]);
				visited[spaces[2 * ind]][spaces[2 * ind + 1]] = 1;
			}
		}
		/*
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cout << visited[i][j] << ' ';
			}
			cout << '\n';
		}
		*/
		int cmp = bfs(q, lab_copy, visited, n);
		// cout << cmp << '\n';
		if(cmp != -1 && cmp < min_time){
			min_time = cmp;
		}
		// cout << min_time << '\n';
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	cout << (min_time == MAX * MAX ? -1 : min_time);
	return 0;
}
