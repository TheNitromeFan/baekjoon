#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[2][1000];
	int points[1000] = {};
	for(int j = 0; j < m; ++j){
		scanf("%d", &a[0][j]);
		if(a[0][j] == 100){
			++points[0];
		}
	}
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &a[1][j]);
			if(a[1][j] == 100 && a[0][j] == 100){
				++points[i];
			}
		}
	}
	int tie = 1;
	for(int i = 1; i < n; ++i){
		if(points[0] == points[i]){
			++tie;
		}
	}
	printf("1 %d", tie);
	return 0;
}
