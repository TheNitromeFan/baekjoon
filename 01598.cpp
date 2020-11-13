#include <cstdio>
#include <cstdlib>

int dist(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", dist((a - 1) % 4, (a - 1) / 4, (b - 1) % 4, (b - 1) / 4));
	return 0;
}
