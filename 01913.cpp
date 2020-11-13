#include <cstdio>
#define MAX 999

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
	int n, find;
	scanf("%d %d", &n, &find);
	static int arr[MAX][MAX];
	int x = n / 2, y = n / 2;
	int dir = 0;
	int cnt = 0, dcnt = 1;
	for(int i = 1; i <= n * n; ++i){
		arr[x][y] = i;
		++cnt;
		x += dx[dir];
		y += dy[dir];
		if(cnt == dcnt){
			cnt = 0;
			dir = (dir + 1) % 4;
			if(dir % 2 == 0){
				++dcnt;
			}
		}
	}
	int ansx = 0, ansy = 0;
	for(x = 0; x < n; ++x){
		for(int y = 0; y < n; ++y){
			printf("%d ", arr[x][y]);
			if(arr[x][y] == find){
				ansx = x + 1;
				ansy = y + 1;
			}
		}
		printf("\n");
	}
	printf("%d %d", ansx, ansy);
	return 0;
}
