#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		if(x == y){
			printf("%d\n", x % 2 ? 2 * x - 1 : 2 * x);
		}else if(x == y + 2){
			printf("%d\n", x % 2 ? 2 * x - 3 : 2 * x - 2);
		}else{
			printf("No Number\n");
		}
	}
	return 0;
}
