#include <cstdio>

int intensity(int r, int g, int b){
	return 2126 * r + 7152 * g + 722 * b;
}

char ascii(int i){
	if(i < 510000){
		return '#';
	}else if(i < 1020000){
		return 'o';
	}else if(i < 1530000){
		return '+';
	}else if(i < 2040000){
		return '-';
	}else{
		return '.';
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int r, g, b;
			scanf("%d %d %d", &r, &g, &b);
			printf("%c", ascii(intensity(r, g, b)));
		}
		printf("\n");
	}
	return 0;
}
