#include <cstdio>

void convert(int number, int base){
	if(number > 0){
		convert(number / base, base);
		printf("%d ", number % base);
	}
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int m;
	scanf("%d", &m);
	int number = 0;
	for(int i = 0; i < m; ++i){
		int x;
		scanf("%d", &x);
		number = number * a + x;
	}
	convert(number, b);
	return 0;
}
