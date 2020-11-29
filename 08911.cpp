#include <cstdio>

int main(){
	int dx[4] = {0, -1, 0, 1};
	int dy[4] = {1, 0, -1, 0};
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		char commands[600];
		scanf("%s", commands);
		int x = 0, y = 0;
		int dir = 0;
		int minX = 0, maxX = 0, minY = 0, maxY = 0;
		for(int i = 0; commands[i] != '\0'; ++i){
			if(commands[i] == 'F'){
				x += dx[dir];
				y += dy[dir];
				if(x < minX){
					minX = x;
				}
				if(x > maxX){
					maxX = x;
				}
				if(y < minY){
					minY = y;
				}
				if(y > maxY){
					maxY = y;
				}
			}else if(commands[i] == 'B'){
				x -= dx[dir];
				y -= dy[dir];
				if(x < minX){
					minX = x;
				}
				if(x > maxX){
					maxX = x;
				}
				if(y < minY){
					minY = y;
				}
				if(y > maxY){
					maxY = y;
				}
			}else if(commands[i] == 'L'){
				dir = (dir + 1) % 4;
			}else if(commands[i] == 'R'){
				dir = (dir + 3) % 4;
			}
		}
		printf("%d\n", (maxX - minX) * (maxY - minY));
	}
	return 0;
}
