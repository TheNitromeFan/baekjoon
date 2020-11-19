#include <cstdio>
#define MAX 20000000

int excess(int h[20], int n, int i, int b){
	if(i == n){
		return b <= 0 ? -b : MAX;
	}else if(b <= 0){
		return -b;
	}else{
		int x = excess(h, n, i + 1, b - h[i]);
		int y = excess(h, n, i + 1, b);
		return (x < y) ? x : y;
	}
}

int main(){
	int n, b;
	scanf("%d %d", &n, &b);
	int h[20];
	for(int i = 0; i < n; ++i){
		scanf("%d", &h[i]);
	}
	printf("%d", excess(h, n, 0, b));
	return 0;
}
