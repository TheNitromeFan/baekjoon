#include <cstdio>
#include <queue>
#define MAX 1001
#define MAX_COMP 500001

void visit(char map[][MAX], int comp[][MAX], int n, int dx[4], int dy[4], int sx, int sy, int label,
			int area[MAX_COMP], int perimeter[MAX_COMP]){
	std::queue<int> q;
	q.push(sx);
	q.push(sy);
	comp[sx][sy] = label;
	int a = 1, p = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == '#' && comp[nx][ny] == 0){
				q.push(nx);
				q.push(ny);
				comp[nx][ny] = label;
				++a;
			}else if(!(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == '#')){
				++p;
			}
		}
	}
	area[label] = a;
	perimeter[label] = p;
}

int main(){
	int n;
	scanf("%d", &n);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	int comp[MAX][MAX] = {};
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int comp_cnt = 0;
	int a[MAX_COMP], p[MAX_COMP];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(map[i][j] == '#' && comp[i][j] == 0){
				++comp_cnt;
				visit(map, comp, n, dx, dy, i, j, comp_cnt, a, p);
			}
		}
	}
	/*
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%d ", comp[i][j]);
		}
		printf("\n");
	}
	*/
	int max_area = 0, min_perimeter = 100000000;
	for(int x = 1; x <= comp_cnt; ++x){
		int area = a[x], perimeter = p[x];
		if(area > max_area || (area == max_area && perimeter < min_perimeter)){
			max_area = area;
			min_perimeter = perimeter;
		}
	}
	printf("%d %d", max_area, min_perimeter);
	return 0;
}
