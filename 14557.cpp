#include <cstdio>


int main(void){
	int r, c;
	scanf("%d", &r);
	scanf("%d", &c);
	int min = r * c / 2;
	int max = r * c - 1;
	printf("%d %d", min, max);
	return 0;
}
