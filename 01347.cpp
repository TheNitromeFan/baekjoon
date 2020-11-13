#include <cstdio>
#include <cstring>
#define MAX (100 + 1)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(){
	int n;
	scanf("%d", &n);
	char moves[MAX];
	scanf("%s", moves);
	bool maze[MAX][MAX] = {};
	int x = 50, y = 50;
	maze[x][y] = true;
	int minx = x, maxx = x, miny = y, maxy = y;
	int dir = 0;
	for(int i = 0; i < n; ++i){
		switch(moves[i]){
			case 'F':
				x += dx[dir];
				y += dy[dir];
				maze[x][y] = true;
				if(x < minx){
					minx = x;
				}else if(x > maxx){
					maxx = x;
				}
				if(y < miny){
					miny = y;
				}else if(y > maxy){
					maxy = y;
				}
				break;
			case 'R':
				dir = (dir + 1) % 4;
				break;
			case 'L':
				dir = (dir + 3) % 4;
				break;
		}
	}
	for(int i = minx; i <= maxx; ++i){
		for(int j = miny; j <= maxy; ++j){
			if(maze[i][j]){
				printf(".");
			}else{
				printf("#");
			}
		}
		printf("\n");
	}
	return 0;
}
