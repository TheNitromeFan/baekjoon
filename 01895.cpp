#include <cstdio>
#include <algorithm>
#define MAX 40

int median(int arr[][MAX], int x, int y){
	int num[9];
	for(int i = x - 1; i <= x + 1; ++i){
		for(int j = y - 1; j <= y + 1; ++j){
			num[(i - x + 1) * 3 + (j - y + 1)] = arr[i][j];
		}
	}
	std::sort(num, num + 9);
	return num[4];
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	int arr[MAX][MAX];
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			scanf("%d", &arr[i][j]);
		}
	}
	int t;
	scanf("%d", &t);
	int ans = 0;
	for(int i = 1; i < r - 1; ++i){
		for(int j = 1; j < c - 1; ++j){
			if(median(arr, i, j) >= t){
				++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
