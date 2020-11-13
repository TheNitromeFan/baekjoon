#include <cstdio>

bool frameFill(int x, int y, int ak){
	return ((x - 1) % ak == 0 && (y - 1) % ak == 0)
	|| (x % ak == 0 && (y - 2) % ak == 0)
	|| ((x - 2) % ak == 0 && y % ak == 0)
	|| (ak == 2);
}

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int ak;
		scanf("%d", &ak);
		printf("%s\n", frameFill(x, y, ak) ? "YES" : "NO");
	}
	return 0;
}
