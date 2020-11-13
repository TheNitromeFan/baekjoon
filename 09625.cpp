#include <cstdio>

int main(){
	int fibs[46] = {0, 1};
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i){
		fibs[i] = fibs[i-1] + fibs[i-2];
	}
	printf("%d %d", fibs[n-1], fibs[n]);
	return 0;
}
