#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#define MAX 21

using namespace std;

int bfs(char map[][MAX], int prevx[][MAX][MAX], int prevy[][MAX][MAX], char moves[][MAX], int h, int w, int n, int sx, int sy){
	queue<int> q;
	bool visited[MAX][MAX][MAX] = {};
	q.push(sx);
	q.push(sy);
	q.push(0);
	visited[sx][sy][0] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int m = q.front();
		q.pop();
		if(map[x][y] == 'Z'){
			return m;
		}
		if(m == n){
			continue;
		}
		for(int k = 0; k < 2; ++k){
			int nx = x, ny = y;
			switch(moves[k][m]){
				case 'S':
					++nx;
					break;
				case 'W':
					--nx;
					break;
				case 'D':
					++ny;
					break;
				case 'A':
					--ny;
					break;
			}
			if(nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] != '@' && !visited[nx][ny][m + 1]){
				q.push(nx);
				q.push(ny);
				q.push(m + 1);
				visited[nx][ny][m + 1] = true;
				prevx[nx][ny][m + 1] = x;
				prevy[nx][ny][m + 1] = y;
			}
		}
	}
	return -1;
}

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	char map[MAX][MAX];
	int sx = -1, sy = -1, fx = -1, fy = -1;
	for(int i = 0; i < h; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < w; ++j){
			if(map[i][j] == 'D'){
				sx = i;
				sy = j;
			}else if(map[i][j] == 'Z'){
				fx = i;
				fy = j;
			}
		}
	}
	int n;
	scanf("%d", &n);
	char moves[2][MAX];
	for(int k = 0; k < n; ++k){
		scanf(" %c %c", &moves[0][k], &moves[1][k]);
	}
	int prevx[MAX][MAX][MAX], prevy[MAX][MAX][MAX];
	int ans = bfs(map, prevx, prevy, moves, h, w, n, sx, sy);
	if(ans != -1){
		printf("YES\n");
		string s = "";
		while(ans > 0){
			int px = prevx[fx][fy][ans];
			int py = prevy[fx][fy][ans];
			if(fx == px + 1){
				s += 'S';
			}else if(fx == px - 1){
				s += 'W';
			}else if(fy == py + 1){
				s += 'D';
			}else{
				s += 'A';
			}
			fx = px;
			fy = py;
			--ans;
		}
		reverse(s.begin(), s.end());
		for(char c : s){
			printf("%c", c);
		}
	}else{
		printf("NO");
	}
	return 0;
}
