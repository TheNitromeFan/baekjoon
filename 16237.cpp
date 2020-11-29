#include <cstdio>

int main(){
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	int boxes = 0;
	boxes += e;
	e = 0;
	boxes += d;
	if(a >= d){
		a -= d;
	}else{
		a = 0;
	}
	d = 0;
	boxes += c;
	if(b >= c){
		b -= c;
	}else if(b + 2 * a >= c){
		a -= 2 * (c - b);
		b = 0;
	}else{
		a = 0;
		b = 0;
	}
	c = 0;
	if(b % 2 == 0){
		if(a >= b / 2){
			boxes += b / 2;
			a -= b / 2;
		}else{
			boxes += b / 2;
			a = 0;
		}
	}else{
		if(a >= b / 2 + 3){
			boxes += b / 2 + 1;
			a -= b / 2 + 3;
		}else{
			boxes += b / 2 + 1;
			a = 0;
		}
	}
	b = 0;
	boxes += a / 5 + (a % 5 != 0);
	a = 0;
	printf("%d", boxes);
	return 0;
}
