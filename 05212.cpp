#include <cstdio>

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char map[11][11], ans[11][11];
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < c; ++j){
			ans[i][j] = map[i][j];
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(map[i][j] == '.'){
				continue;
			}
			int cnt = 0;
			if(i == 0 || map[i-1][j] == '.'){
				++cnt;
			}
			if(j == 0 || map[i][j-1] == '.'){
				++cnt;
			}
			if(i == r-1 || map[i+1][j] == '.'){
				++cnt;
			}
			if(j == c-1 || map[i][j+1] == '.'){
				++cnt;
			}
			if(cnt >= 3){
				ans[i][j] = '.';
			}
		}
	}
	int top = 0, bottom = r-1, left = 0, right = c-1;
	bool flag;
	flag = false;
	while(true){
		for(int j = 0; j < c; ++j){
			if(ans[top][j] == 'X'){
				flag = true;
				break;
			}
		}
		if(flag){
			break;
		}
		++top;
	}
	flag = false;
	while(true){
		for(int j = 0; j < c; ++j){
			if(ans[bottom][j] == 'X'){
				flag = true;
				break;
			}
		}
		if(flag){
			break;
		}
		--bottom;
	}
	flag = false;
	while(true){
		for(int i = 0; i < r; ++i){
			if(ans[i][left] == 'X'){
				flag = true;
				break;
			}
		}
		if(flag){
			break;
		}
		++left;
	}
	flag = false;
	while(true){
		for(int i = 0; i < r; ++i){
			if(ans[i][right] == 'X'){
				flag = true;
				break;
			}
		}
		if(flag){
			break;
		}
		--right;
	}
	for(int i = top; i <= bottom; ++i){
		for(int j = left; j <= right; ++j){
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
