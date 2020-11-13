#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int x[501], y[501];
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &x[i], &y[i]);
	}
	int maxDist = 0;
	int i1 = 1, i2 = 2;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j < i; ++j){
			int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			if(maxDist < dist){
				maxDist = dist;
				i1 = j;
				i2 = i;
			}
		}
	}
	printf("%d %d", i1, i2);
	return 0;
}
