#include <cstdio>
#define MAX (50 + 1)

int diff(char drawing[][5][8], int a, int b){
	int ret = 0;
	for(int j = 0; j < 5; ++j){
		for(int k = 0; k < 7; ++k){
			if(drawing[a][j][k] != drawing[b][j][k]){
				++ret;
			}
		}
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	char drawing[MAX][5][8];
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < 5; ++j){
			scanf("%s", drawing[i][j]);
		}
	}
	int min_diff = 5 * 7 + 1;
	int min_a = 0, min_b = 0;
	for(int b = 1; b <= n; ++b){
		for(int a = 1; a < b; ++a){
			int cmp = diff(drawing, a, b);
			if(cmp < min_diff){
				min_diff = cmp;
				min_a = a;
				min_b = b;
			}
		}
	}
	printf("%d %d", min_a, min_b);
	return 0;
}
