#include <cstdio>
#include <cstdlib>

int dist(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
	int a, b, c, d, t;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &t);
	printf("%c", (dist(a, b, c, d) <= t && (t - dist(a, b, c, d)) % 2 == 0) ? 'Y' : 'N');
	return 0;
}
