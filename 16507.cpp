#include <cstdio>

int main(){
	int r, c, q;
	scanf("%d %d %d", &r, &c, &q);
	static int pic[1001][1001], arr[1001][1001] = {};
	for(int i = 1; i <= r; ++i){
		for(int j = 1; j <= c; ++j){
			scanf("%d", &pic[i][j]);
			arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + pic[i][j];
			// printf("%d ", arr[i][j]);
		}
		// printf("\n");
	}
	for(int k = 0; k < q; ++k){
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		printf("%d\n", (arr[r2][c2] - arr[r1-1][c2] - arr[r2][c1-1] + arr[r1-1][c1-1]) / ((r2-r1+1) * (c2-c1+1)));
	}
	return 0;
}
