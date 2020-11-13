#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int sum;
		scanf("%d", &sum);
		printf("Case %d:\n", a0);
		if(sum < 7){
			for(int i = 1, j = sum - i; i <= j; ++i, --j){
				printf("(%d,%d)\n", i, j);
			}
		}else{
			for(int i = sum - 6, j = sum - i; i  <= j; ++i, --j){
				printf("(%d,%d)\n", i, j);
			}
		}
	}
	return 0;
}
