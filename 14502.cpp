#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int bfs(int grid[][8], int n, int m){
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	bool visited[8][8];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			visited[i][j] = false;
		}
	}
	queue<int> q;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(grid[i][j] != 2 || visited[i][j]){
				continue;
			}
			visited[i][j] = true;
			q.push(i);
			q.push(j);
			while(!q.empty()){
				int x = q.front();
				q.pop();
				int y = q.front();
				q.pop();
				for(int ind = 0; ind < 4; ++ind){
					if(x+dx[ind] >= 0 && x+dx[ind] < n && y+dy[ind] >= 0 && y+dy[ind] < m
					&& grid[x+dx[ind]][y+dy[ind]] != 1 && !visited[x+dx[ind]][y+dy[ind]]){
						grid[x+dx[ind]][y+dy[ind]] = 2;
						q.push(x+dx[ind]);
						q.push(y+dy[ind]);
						visited[x+dx[ind]][y+dy[ind]] = true;
					}
				}
			}
		}
	}
	int space = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(grid[i][j] == 0){
				++space;
			}
		}
	}
	return space;
}

int main(){
	int n, m;
	cin >> n >> m;
	int lab[8][8];
	vector<int> spaces;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> lab[i][j];
			if(lab[i][j] == 0){
				spaces.push_back(i);
				spaces.push_back(j);
			}
		}
	}
	int lab_copy[8][8];
	string bitmask(3, 1);
	bitmask.resize(spaces.size() / 2, 0);
	int max_spaces = 0;
	do{
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				lab_copy[i][j] = lab[i][j];
			}
		}
		for(unsigned ind = 0; ind < spaces.size() / 2; ++ind){
			if(bitmask[ind]){
				lab_copy[spaces[2*ind]][spaces[2*ind+1]] = 1;
			}
		}
		/*
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cout << lab_copy[i][j] << ' ';
			}
			cout << '\n';
		}
		*/
		int cmp = bfs(lab_copy, n, m);
		if(cmp > max_spaces){
			max_spaces = cmp;
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	cout << max_spaces;
	return 0;
}
