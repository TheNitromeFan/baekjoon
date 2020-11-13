#include <cstdio>

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int a[25];
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		int idx = 0;
		while(idx < n){
			int x = a[idx];
			printf("%d ", x);
			while(idx < n && a[idx] == x){
				++idx;
			}
		}
		printf("$\n");
	}
	return 0;
}
