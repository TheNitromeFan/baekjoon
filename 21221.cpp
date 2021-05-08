#include <cstdio>
#define MAX 101

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char a[MAX][MAX], copy[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", a[i]);
		for(int j = 0; j < m; ++j){
			copy[i][j] = '.';
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(a[i][j] == '#'){
				copy[i][j] = '#';
				copy[i][j + 1] = '#';
				copy[i + 1][j] = '#';
				copy[i + 1][j + 1] = '#';
			}
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			printf("%c", copy[i][j]);
		}
		printf("\n");
	}
	return 0;
}
