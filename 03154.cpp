#include <cstdio>
#include <cstdlib>

int x[10] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};
int y[10] = {0, 3, 3, 3, 2, 2, 2, 1, 1, 1};

int effort(int i, int j){
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main(){
	int h, m;
	scanf("%d:%d", &h, &m);
	int minEffort = 1000;
	int c = h, d = m;
	for(int a = h; a < 100; a += 24){
		for(int b = m; b < 100; b += 60){
			int e = effort(a / 10, a % 10) + effort(a % 10, b / 10) + effort(b / 10, b % 10);
			if(e < minEffort){
				minEffort = e;
				c = a;
				d = b;
			}
		}
	}
	printf("%02d:%02d", c, d);
	return 0;
}
