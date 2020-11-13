#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		for(int j = 0; j < x; ++j){
			printf("=");
		}
		printf("\n");
	}
	return 0;
}
