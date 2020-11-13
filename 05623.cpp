#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	static int s[1001][1001];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &s[i][j]);
		}
	}
	if(n == 2){
		printf("1 1");
		return 0;
	}
	int a[1001];
	a[1] = (s[1][2] + s[1][3] - s[2][3]) / 2;
	for(int i = 2; i <= n; ++i){
		a[i] = s[i-1][i] - a[i-1];
	}
	for(int i = 1; i <= n; ++i){
		printf("%d ", a[i]);
	}
	return 0;
}
