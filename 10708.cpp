#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	int a[101];
	for(int i = 1; i <= m; ++i){
		scanf("%d", &a[i]);
	}
	int b[101][101];
	int points[101] = {};
	for(int i = 1; i <= m; ++i){
		int x = 0;
		for(int j = 1; j <= n; ++j){
			scanf("%d", &b[i][j]);
			if(b[i][j] == a[i]){
				++points[j];
			}else{
				++x;
			}
		}
		points[a[i]] += x;
	}
	for(int i = 1; i <= n; ++i){
		printf("%d\n", points[i]);
	}
	return 0;
}
