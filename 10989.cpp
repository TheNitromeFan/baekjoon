#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	scanf("%d", &n);
	int *count = (int *)calloc(10001, sizeof(int));
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		++count[x];
	}
	for(int i = 1; i <= 10000; ++i){
		for(int j = 0; j < count[i]; ++j){
			printf("%d\n", i);
		}
	}
	return 0;
}
