#include <cstdio>
#include <cstdlib>

int dist(int x, int y, int a, int b){
	return abs(x - a) + abs(y - b);
}

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	int n;
	scanf("%d", &n);
	int ans_x, ans_y;
	scanf("%d %d", &ans_x, &ans_y);
	for(int i = 1; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		if(dist(x, y, ans_x, ans_y) > dist(x, y, a, b)){
			ans_x = a;
			ans_y = b;
		}
	}
	printf("%d %d", ans_x, ans_y);
	return 0;
}
