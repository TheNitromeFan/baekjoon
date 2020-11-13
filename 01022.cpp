#include <cstdio>

using namespace std;

int main(){
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};
	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	int map[50][5];
	for(int i = 0; i <= r2-r1; ++i){
		for(int j = 0; j <= c2-c1; ++j){
			map[i][j] = 0;
		}
	}
	int x = 0, y = 0;
	int direction = 3;
	int dcount = 1;
	int number = 1;
	int count = 0;
	while(map[0][0] == 0 || map[0][c2-c1] == 0 || map[r2-r1][0] == 0 || map[r2-r1][c2-c1] == 0){
		if(x >= r1 && x <= r2 && y >= c1 && y <= c2){
			map[x-r1][y-c1] = number;
		}
		++number;
		++count;
		x += dx[direction];
		y += dy[direction];
		if(count == dcount){
			count = 0;
			direction = (direction + 1) % 4;
			if(direction % 2 == 1){
				++dcount;
			}
		}
	}
	count = 0;
	while(number){
		number /= 10;
		++count;
	}
	for(int i = 0; i <= r2-r1; ++i){
		for(int j = 0; j <= c2-c1; ++j){
			printf("%*d ", count, map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
