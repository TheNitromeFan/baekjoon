#include <cstdio>
#define MAX (100 + 1)

void visit(char floor[][MAX], bool visited[][MAX], int n, int m, int x, int y){
	visited[x][y] = true;
	if(floor[x][y] == '-'){
		if(y - 1 >= 0 && floor[x][y - 1] == '-' && !visited[x][y - 1]){
			visit(floor, visited, n, m, x, y - 1);
		}
		if(y + 1 < m && floor[x][y + 1] == '-' && !visited[x][y + 1]){
			visit(floor, visited, n, m, x, y + 1);
		}
	}else{
		if(x - 1 >= 0 && floor[x - 1][y] == '|' && !visited[x - 1][y]){
			visit(floor, visited, n, m, x - 1, y);
		}
		if(x + 1 < n && floor[x + 1][y] == '|' && !visited[x + 1][y]){
			visit(floor, visited, n, m, x + 1, y);
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char floor[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", floor[i]);
	}
	bool visited[MAX][MAX] = {};
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(!visited[i][j]){
				visit(floor, visited, n, m, i, j);
				++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
