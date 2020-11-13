#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int max = -1000000, min = 1000000;
	int x;
	for(int i = 0; i < n; ++i){
		scanf("%d", &x);
		if(x > max){
			max = x;
		}
		if(x < min){
			min = x;
		}
	}
	printf("%d %d", min, max);
	return 0;
}
