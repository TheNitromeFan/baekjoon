#include <cstdio>

bool split(int a[100], int n, int low1, int high1, int low2, int high2){
	int x1 = 0, x2 = 0, spares = 0;
	for(int i = 0; i < n; ++i){
		x1 += a[i] / 2;
		x2 += a[i] / 2;
		spares += a[i] % 2;
	}
	for(int i = 0, j = spares; j >= 0; ++i, --j){
		if(x1 + i >= low1 && x1 + i <= high1 && x2 + j >= low2 && x2 + j <= high2){
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	int a[100];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	printf("%s", split(a, n, x1, y1, x2, y2) ? "Yes" : "No");
	return 0;
}
