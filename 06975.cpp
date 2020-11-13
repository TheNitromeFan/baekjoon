#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1; i < n; ++i){
			if(n % i == 0){
				sum += i;
			}
		}
		printf("%d is ", n);
		if(sum < n){
			printf("a deficient");
		}else if(sum > n){
			printf("an abundant");
		}else{
			printf("a perfect");
		}
		printf(" number.\n\n");
	}
	return 0;
}
