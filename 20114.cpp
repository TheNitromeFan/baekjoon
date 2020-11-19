#include <cstdio>

char letter(char s[][1001], int h, int w, int x){
	for(int i = 0; i < h; ++i){
		for(int j = w * x; j < w * (x + 1); ++j){
			if(s[i][j] != '?'){
				return s[i][j];
			}
		}
	}
	return '?';
}

int main(){
	int n, h, w;
	scanf("%d %d %d", &n, &h, &w);
	char s[10][1001];
	for(int i = 0; i < h; ++i){
		scanf("%s", s[i]);
	}
	for(int j = 0; j < n; ++j){
		printf("%c", letter(s, h, w, j));
	}
	return 0;
}
