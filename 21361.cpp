#include <cstdio>
#define MAX 2001

int main(){
	int r, c, n;
	scanf("%d %d %d", &r, &c, &n);
	char commands[MAX];
	scanf("%s", commands);
	char map[MAX][MAX];
	int x = -1, y = -1;
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < c; ++j){
			if(map[i][j] == 'O'){
				x = i;
				y = j;
			}
		}
	}
	bool cleaned[MAX][MAX] = {};
	int cnt = 0;
	cleaned[x][y] = true;
	++cnt;
	for(int i = 0; i < n; ++i){
		if(commands[i] == '>'){
			while(map[x][y + 1] != '#'){
				++y;
				if(!cleaned[x][y]){
					cleaned[x][y] = true;
					++cnt;
				}
			}
		}else if(commands[i] == '<'){
			while(map[x][y - 1] != '#'){
				--y;
				if(!cleaned[x][y]){
					cleaned[x][y] = true;
					++cnt;
				}
			}
		}else if(commands[i] == 'v'){
			while(map[x + 1][y] != '#'){
				++x;
				if(!cleaned[x][y]){
					cleaned[x][y] = true;
					++cnt;
				}
			}
		}else{
			while(map[x - 1][y] != '#'){
				--x;
				if(!cleaned[x][y]){
					cleaned[x][y] = true;
					++cnt;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
