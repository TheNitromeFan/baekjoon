#include <cstdio>
#include <cmath>

int main(){
	int t = 0;
	while(true){
		++t;
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0 && b == 0 && c == 0){
			break;
		}
		printf("Triangle #%d\n", t);
		if(c == -1){
			printf("c = %.3f", sqrt(a * a + b * b));
		}else if(a == -1){
			if(b < c){
				printf("a = %.3f", sqrt(c * c - b * b));
			}else{
				printf("Impossible.");
			}
		}else if(b == -1){
			if(a < c){
				printf("b = %.3f", sqrt(c * c - a * a));
			}else{
				printf("Impossible.");
			}
		}
		printf("\n\n");
	}
	return 0;
}
