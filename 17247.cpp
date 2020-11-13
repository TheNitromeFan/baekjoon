#include <cstdio>
#include <cstdlib>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static int arr[1001][1001];
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == 1 && x1 == 0){
				x1 = i;
				y1 = j;
			}else if(arr[i][j] == 1){
				x2 = i;
				y2 = j;
			}
		}
	}
	printf("%d", abs(x2 - x1) + abs(y2 - y1));
	return 0;
}
