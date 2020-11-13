#include <cstdio>
#include <cmath>

int main(){
	int n;
	scanf("%d", &n);
	if(n <= 4){
		printf("4");
		return 0;
	}
	int x = (int)sqrt(n);
	if(x * x == n){
		printf("%d", 4 * x - 4);
	}else if(x * x + x >= n){
		printf("%d", 4 * x - 2);
	}else{
		printf("%d", 4 * x);
	}
	return 0;
}
