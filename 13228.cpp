#include <cstdio>
#include <cstdlib>

int dist(int h1, int x1, int y1, int h2, int x2, int y2){
	return h1 + h2 + abs(x1 - x2) + abs(y1 - y2);
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int h1, x1, y1, h2, x2, y2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &h1, &x2, &y2, &h2);
		printf("%d\n", dist(h1, x1, y1, h2, x2, y2));
	}
	return 0;
}
