#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		int press[1001] = {};
		for(int i = 0; i < n; ++i){
			char letter;
			int a, b;
			scanf(" %c %d %d", &letter, &a, &b);
			for(int j = a; j < b; ++j){
				++press[j];
			}
		}
		for(int j = 0; j <= 1000; ++j){
			if(press[j] > 0){
				printf("%c", 'A' + (press[j] - 1));
			}
		}
		printf("\n");
	}
	return 0;
}
