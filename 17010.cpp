#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		char c;
		scanf("%d %c\n", &n, &c);
		for(int j = 0; j < n; ++j){
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}
