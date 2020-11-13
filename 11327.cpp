#include <cstdio>

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int a[10];
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		long long x, y;
		scanf("%lld %lld", &x, &y);
		long long fx = 0, xi = 1;
		for(int i = 0; i < n; ++i){
			fx += a[i] * xi;
			xi *= x;
		}
		if(y < fx){
			printf("Inside\n");
		}else if(y == fx){
			printf("On\n");
		}else{
			printf("Outside\n");
		}
	}
	return 0;
}
