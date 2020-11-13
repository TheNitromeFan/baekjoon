#include <cstdio>
#include <cstdlib>

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	int dx = 1;
	int dist = 0;
	while(true){
		int nx = x + dx;
		if((nx - y) * (x - y) <= 0){
			dist += abs(x - y);
			break;
		}
		dist += 2 * abs(dx);
		dx *= -2;
	}
	printf("%d", dist);
	return 0;
}
