#include <cstdio>
#include <cstdlib>
#include <queue>

using std::queue;

int components(int field[][50], int n, int m){
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	bool visited[50][50];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			visited[i][j] = false;
		}
	}
	queue<int> q;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(field[i][j] == 1 && !visited[i][j]){
				q.push(i);
				q.push(j);
				visited[i][j] = true;
				++ans;
				while(!q.empty()){
					int x = q.front();
					q.pop();
					int y = q.front();
					q.pop();
					for(int ind = 0; ind < 4; ++ind){
						if(x+dx[ind] >= 0 && x+dx[ind] < n && y+dy[ind] >= 0 && y+dy[ind] < m
						&& field[x+dx[ind]][y+dy[ind]] == 1 && !visited[x+dx[ind]][y+dy[ind]]){
							q.push(x+dx[ind]);
							q.push(y+dy[ind]);
							visited[x+dx[ind]][y+dy[ind]] = true;
						}
					}
				}
			}
		}
	}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int field[50][50];
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				field[i][j] = 0;
			}
		}
		for(int a1 = 0; a1 < k; ++a1){
			int x, y;
			scanf("%d %d", &x, &y);
			field[x][y] = 1;
		}
		printf("%d\n", components(field, n, m));
	}
	return 0;
}
