#include <cstdio>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	for(int i = 1; i <= 1000; ++i){
		if(a % i == 0 && b % i == 0){
			printf("%d %d %d\n", i, a / i, b / i);
		}
	}
	return 0;
}
