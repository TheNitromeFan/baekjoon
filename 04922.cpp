#include <cstdio>

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		printf("%d => %d\n", n, n * n - n + 1);
	}
	return 0;
}
