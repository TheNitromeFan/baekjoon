#include <cstdio>

int wins(int a[][100], int r, int c, int x, int y){
	int ret = 0;
	bool flag;
	flag = true;
	for(int i = x - 1; i >= 0; --i){
		if(a[i][y] >= a[x][y]){
			flag = false;
			break;
		}
	}
	if(flag){
		++ret;
	}
	flag = true;
	for(int i = x + 1; i < r; ++i){
		if(a[i][y] >= a[x][y]){
			flag = false;
			break;
		}
	}
	if(flag){
		++ret;
	}
	flag = true;
	for(int j = y - 1; j >= 0; --j){
		if(a[x][j] >= a[x][y]){
			flag = false;
			break;
		}
	}
	if(flag){
		++ret;
	}
	flag = true;
	for(int j = y + 1; j < c; ++j){
		if(a[x][j] >= a[x][y]){
			flag = false;
			break;
		}
	}
	if(flag){
		++ret;
	}
	return ret;
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	int a[100][100];
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	int ans = 0;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			ans += wins(a, r, c, i, j);
		}
	}
	printf("%d", ans);
	return 0;
}
