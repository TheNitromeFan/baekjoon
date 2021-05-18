#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
#define MAX 1001

using namespace std;

void bfs(char map[][MAX], int component[][MAX], int r, int c, vector<int> &component_sizes, int sx, int sy, int label, int dx[4], int dy[4]){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	component[sx][sy] = label;
	int cnt = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		++cnt;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] == '0' && component[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				component[nx][ny] = label;
			}
		}
	}
	component_sizes.push_back(cnt);
}

void get_components(char map[][MAX], int component[][MAX], int n, int m, vector<int> &component_sizes, int dx[4], int dy[4]){
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(map[i][j] == '0' && component[i][j] == -1){
				bfs(map, component, n, m, component_sizes, i, j, cnt, dx, dy);
				++cnt;
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	int component[MAX][MAX];
	memset(component, -1, sizeof(component));
	vector<int> component_sizes;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	get_components(map, component, n, m, component_sizes, dx, dy);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(map[i][j] == '0'){
				printf("0");
				continue;
			}
			unordered_set<int> adjacent_components;
			for(int k = 0; k < 4; ++k){
				int ni = i + dx[k], nj = j + dy[k];
				if(ni >= 0 && ni < n && nj >= 0 && nj < m && map[ni][nj] == '0'){
					adjacent_components.insert(component[ni][nj]);
				}
			}
			int ans = 1;
			for(int x : adjacent_components){
				ans += component_sizes[x];
			}
			printf("%d", ans % 10);
		}
		printf("\n");
	}
	return 0;
}
