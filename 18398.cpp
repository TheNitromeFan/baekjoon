#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		for(int j = 0; j < n; ++j){
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%d %d\n", a + b, a * b);
		}
	}
	return 0;
}
