#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		printf("%d\n", (n + 1) / 2 * (n + 1) / 2);
	}
	return 0;
}
