#include <cstdio>
#include <cstdlib>
#define MAX 2000

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		int a[MAX];
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		int x = 0;
		for(int i = 1; i < n; ++i){
			x = gcd(x, abs(a[i] - a[i - 1]));
		}
		if(x > 0){
			printf("%d\n", x);
		}else{
			printf("INFINITY\n");
		}
	}
	return 0;
}
