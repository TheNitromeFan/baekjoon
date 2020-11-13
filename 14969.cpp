#include <cstdio>

int main(){
	while(true){
		int n, m;
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0){
			break;
		}
		int a[1000];
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		int sum = -1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < i; ++j){
				if(a[j] + a[i] <= m && sum < a[j] + a[i]){
					sum = a[j] + a[i];
				}
			}
		}
		if(sum != -1){
			printf("%d\n", sum);
		}else{
			printf("NONE\n");
		}
	}
	return 0;
}
