#include <cstdio>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int floor[50][50]; // floor[y][x]

bool cleaned[50][50];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int r, c, d;
	scanf("%d %d %d", &r, &c, &d);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &floor[i][j]);
		}
	}
	int cnt = 0;
	while(true){
		// printf("r: %d, c: %d\n", r, c);
		if(!cleaned[r][c]){
			cleaned[r][c] = true;
			++cnt;
			continue;
		}
		int turn_cnt = 0;
		while(turn_cnt < 4){
			d = (d + 3) % 4;
			if(r + dx[d] >= 0 && r + dx[d] < n && c + dy[d] >= 0 && c + dy[d] < m
			   && floor[r + dx[d]][c + dy[d]] == 0 && !cleaned[r + dx[d]][c + dy[d]]){
			    r += dx[d];
			    c += dy[d];
			    break;
			}
			++turn_cnt;
		}
		if(turn_cnt < 4){
			continue;
		}
		if(r - dx[d] >= 0 && r - dx[d] < n && c - dy[d] >= 0 && c - dy[d] < m
		   && floor[r - dx[d]][c - dy[d]] == 0){
		    r -= dx[d];
		    c -= dy[d];
		    continue;
		}
		break;
	}
	printf("%d", cnt);
	return 0;
}
