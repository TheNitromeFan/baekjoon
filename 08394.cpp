#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int prev = 0, cur = 1;
	for(int i = 1; i <= n; ++i){
		int tmp = cur;
		cur = (prev + cur) % 10;
		prev = tmp;
	}
	printf("%d", cur);
	return 0;
}
