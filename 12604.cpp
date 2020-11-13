#include <cstdio>
#define MAX (2000 + 1)

void select(int items[MAX], int n, int sum){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j < i; ++j){
			if(items[j] + items[i] == sum){
				printf("%d %d", j, i);
				return;
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int t = 1; t <= n; ++t){
		int c, i;
		scanf("%d %d", &c, &i);
		int items[MAX];
		for(int j = 1; j <= i; ++j){
			scanf("%d", &items[j]);
		}
		printf("Case #%d: ", t);
		select(items, i, c);
		printf("\n");
	}
	return 0;
}
