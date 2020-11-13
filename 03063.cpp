#include <cstdio>


long max(long a, long b){
	
	if(a > b) return a;
	else return b;
}

long min(long a, long b){
	
	if(a < b) return a;
	else return b;
}

long covered(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4){
	
	long width = min(x2, x4) - max(x1, x3);
	long height = min(y2, y4) - max(y1, y3);
	if(width > 0 && height > 0) return width * height;
	else return 0;
}

long visible(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4){
	
	return (x2 - x1) * (y2 - y1) - covered(x1, y1, x2, y2, x3, y3, x4, y4);
}

int main(void){
	
	int t;
	scanf("%d", &t);
	long x1, y1, x2, y2, x3, y3, x4, y4;
	for(int i = 0; i < t; i++){
		scanf("%ld %ld %ld %ld %ld %ld %ld %ld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		printf("%ld\n", visible(x1, y1, x2, y2, x3, y3, x4, y4));
	}
	return 0;
}
