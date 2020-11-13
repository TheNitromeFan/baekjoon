#include <cstdio>

int main(){
	int a = 0, b = 0;
	while(true){
		int inst;
		scanf("%d", &inst);
		if(inst == 1){
			char x;
			int n;
			scanf(" %c %d", &x, &n);
			if(x == 'A'){
				a = n;
			}else{
				b = n;
			}
		}else if(inst == 2){
			char x;
			scanf(" %c", &x);
			if(x == 'A'){
				printf("%d\n", a);
			}else{
				printf("%d\n", b);
			}
		}else if(inst == 3){
			char x, y;
			scanf(" %c %c", &x, &y);
			if(x == 'A' && y == 'A'){
				a += a;
			}else if(x == 'A'){
				a += b;
			}else if(y == 'A'){
				b += a;
			}else{
				b += b;
			}
		}else if(inst == 4){
			char x, y;
			scanf(" %c %c", &x, &y);
			if(x == 'A' && y == 'A'){
				a *= a;
			}else if(x == 'A'){
				a *= b;
			}else if(y == 'A'){
				b *= a;
			}else{
				b *= b;
			}
		}else if(inst == 5){
			char x, y;
			scanf(" %c %c", &x, &y);
			if(x == 'A' && y == 'A'){
				a -= a;
			}else if(x == 'A'){
				a -= b;
			}else if(y == 'A'){
				b -= a;
			}else{
				b -= b;
			}
		}else if(inst == 6){
			char x, y;
			scanf(" %c %c", &x, &y);
			if(x == 'A' && y == 'A'){
				a /= a;
			}else if(x == 'A'){
				a /= b;
			}else if(y == 'A'){
				b /= a;
			}else{
				b /= b;
			}
		}else{
			break;
		}
	}
	return 0;
}
