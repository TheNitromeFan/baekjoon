#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int sum = 0, max = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x > max){
			max = x;
		}
		sum += x;
	}
	printf("%d", sum - max);
	return 0;
}
