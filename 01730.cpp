#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	char paper[11][11] = {};
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			paper[i][j] = '.';
		}
	}
	char s[251];
	scanf("%s", s);
	int x = 0, y = 0;
	for(int i = 0; s[i] != '\0'; ++i){
		int nx = x, ny = y;
		if(s[i] == 'D'){
			++nx;
		}else if(s[i] == 'R'){
			++ny;
		}else if(s[i] == 'L'){
			--ny;
		}else if(s[i] == 'U'){
			--nx;
		}
		if(nx < 0 || nx >= n || ny < 0 || ny >= n){
			continue;
		}
		if(s[i] == 'D' || s[i] == 'U'){
			if(paper[x][y] == '.' || paper[x][y] == '|'){
				paper[x][y] = '|';
			}else{
				paper[x][y] = '+';
			}
			if(paper[nx][ny] == '.' || paper[nx][ny] == '|'){
				paper[nx][ny] = '|';
			}else{
				paper[nx][ny] = '+';
			}
		}else if(s[i] == 'L' || s[i] == 'R'){
			if(paper[x][y] == '.' || paper[x][y] == '-'){
				paper[x][y] = '-';
			}else{
				paper[x][y] = '+';
			}
			if(paper[nx][ny] == '.' || paper[nx][ny] == '-'){
				paper[nx][ny] = '-';
			}else{
				paper[nx][ny] = '+';
			}
		}
		x = nx;
		y = ny;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%c", paper[i][j]);
		}
		printf("\n");
	}
	return 0;
}
