#include <cstdio>
#include <algorithm>
#define MAX 1024

int second_greatest(int a[][MAX], int x, int y){
	int b[4] = {a[x][y], a[x][y + 1], a[x + 1][y], a[x + 1][y + 1]};
	std::sort(b, b + 4);
	return b[2];
}

int main(){
	int n;
	scanf("%d", &n);
	static int a[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	while(n > 1){
		n /= 2;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				a[i][j] = second_greatest(a, 2 * i, 2 * j);
			}
		}
	}
	printf("%d", a[0][0]);
	return 0;
}
