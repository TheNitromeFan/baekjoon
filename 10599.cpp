#include <cstdio>

int main(){
	while(true){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(a == 0 && b == 0 && c == 0 && d == 0){
			break;
		}
		printf("%d %d\n", c - b, d - a);
	}
	return 0;
}
