#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int a0 = 1; a0 <= n; ++a0){
		int num, den;
		scanf("%d %d", &num, &den);
		int i = num / den, n = num % den;
		printf("Case %d: ", a0);
		if(i == 0 && n == 0){
			printf("0");
		}else if(i == 0){
			printf("%d/%d", n, den);
		}else if(n == 0){
			printf("%d", i);
		}else{
			printf("%d %d/%d", i, n, den);
		}
		printf("\n");
	}
	return 0;
}
