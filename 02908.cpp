#include <cstdio>


int max(int a, int b){
	
	if(a > b) return a;
	else return b;
}

int flipped(int n){
	
	int reverse = 0;
	while(n){
		reverse *= 10;
		reverse += n % 10;
		n /= 10;
	}
	return reverse;
}

int main(void){
	
	int a, b;
	scanf("%d %d", &a, &b);
	int x = flipped(a), y = flipped(b);
	printf("%d", max(x, y));
	return 0;
}
