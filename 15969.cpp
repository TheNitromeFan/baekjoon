#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int max = -1, min = 1001;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(max < x){
			max = x;
		}
		if(min > x){
			min = x;
		}
	}
	printf("%d", max - min);
	return 0;
}
