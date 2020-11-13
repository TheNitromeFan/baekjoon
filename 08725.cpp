#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int sum = 0;
	for(int i = 0; i < n; ++i){
		int max = 0;
		for(int j = 0; j < n; ++j){
			int x;
			scanf("%d", &x);
			if(max < x){
				max = x;
			}
		}
		sum += max;
	}
	printf("%d", sum);
	return 0;
}
