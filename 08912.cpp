#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int a[1000];
		int n;
		scanf("%d", &n);
		int sum = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
			for(int j = 0; j < i; ++j){
				if(a[j] <= a[i]){
					++sum;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
