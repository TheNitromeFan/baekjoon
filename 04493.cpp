#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d\n", &n);
		int a = 0, b = 0;
		for(int j = 0; j < n; ++j){
			char c, d;
			scanf("%c %c\n", &c, &d);
			if((c == 'R' && d == 'S') || (c == 'P' && d == 'R') || (c == 'S' && d == 'P')){
				++a;
			}else if((c == 'R' && d == 'P') || (c == 'P' && d == 'S') || (c == 'S' && d == 'R')){
				++b;
			}
		}
		if(a > b){
			printf("Player 1\n");
		}else if(a < b){
			printf("Player 2\n");
		}else{
			printf("TIE\n");
		}
	}
	return 0;
}
