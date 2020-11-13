#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x == n){
			printf("1 ");
		}else{
			printf("%d ", x + 1);
		}
	}
	return 0;
}
