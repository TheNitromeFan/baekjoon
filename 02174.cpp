#include <cstdio>
#define MAX (100 + 1)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(){
	int map[MAX][MAX] = {};
	int a, b;
	scanf("%d %d", &a, &b);
	int n, m;
	scanf("%d %d", &n, &m);
	int posx[MAX], posy[MAX];
	int move[MAX];
	for(int robot = 1; robot <= n; ++robot){
		int x, y;
		char dir;
		scanf("%d %d %c", &x, &y, &dir);
		map[x][y] = robot;
		posx[robot] = x;
		posy[robot] = y;
		if(dir == 'E'){
			move[robot] = 0;
		}else if(dir == 'S'){
			move[robot] = 1;
		}else if(dir == 'W'){
			move[robot] = 2;
		}else if(dir == 'N'){
			move[robot] = 3;
		}
	}
	for(int command = 0; command < m; ++command){
		/*
		for(int r = 1; r <= n; ++r){
			printf("%d %d %d\n", posx[r], posy[r], move[r]);
		}
		*/
		int robot, repeat;
		char prompt;
		scanf("%d %c %d", &robot, &prompt, &repeat);
		for(int i = 0; i < repeat; ++i){
			if(prompt == 'L'){
				move[robot] = (move[robot] + 3) % 4;
			}else if(prompt == 'R'){
				move[robot] = (move[robot] + 1) % 4;
			}else if(prompt == 'F'){
				map[posx[robot]][posy[robot]] = 0;
				posx[robot] += dx[move[robot]];
				posy[robot] += dy[move[robot]];
				if(posx[robot] == 0 || posx[robot] > a || posy[robot] == 0 || posy[robot] > b){
					printf("Robot %d crashes into the wall", robot);
					return 0;
				}else if(map[posx[robot]][posy[robot]] != 0){
					printf("Robot %d crashes into robot %d", robot, map[posx[robot]][posy[robot]]);
					return 0;
				}
				map[posx[robot]][posy[robot]] = robot;
			}
		}
	}
	printf("OK");
	return 0;
}
