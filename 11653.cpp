#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	while(n % 2 == 0){
		printf("2\n");
		n /= 2;
	}
	for(int p = 3; p*p <= n; p += 2){
		while(n % p == 0){
			printf("%d\n", p);
			n /= p;
		}
	}
	if(n > 1){
		printf("%d\n", n);
	}
	return 0;
}
