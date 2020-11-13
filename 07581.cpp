#include <cstdio>

int main(){
	while(true){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(a == 0 && b == 0 && c == 0 && d == 0){
			break;
		}
		if(a && b && c){
			d = a * b * c;
		}else if(a && b && d){
			c = d / a / b;
		}else if(a && c && d){
			b = d / a / c;
		}else{
			a = d / b / c;
		}
		printf("%d %d %d %d\n", a, b, c, d);
	}
	return 0;
}
