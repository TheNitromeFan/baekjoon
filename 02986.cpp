#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	if(n == 1){
		printf("0");
		return 0;
	}
	int p;
	for(p = 2; p*p <= n; ++p){
		if(n % p == 0){
			break;
		}
	}
	if(n % p == 0){
		printf("%d", n - n/p);
	}else{
		printf("%d", n - 1);
	}
	return 0;
}
