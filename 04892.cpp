#include <cstdio>

int main(){
	int cnt = 0;
	while(true){
		++cnt;
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		printf("%d. ", cnt);
		if(n % 2 == 0){
			printf("even ");
		}else{
			printf("odd ");
		}
		printf("%d\n", n / 2);
	}
	return 0;
}
