#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int height = 0;
	while(n >= 0){
		++height;
		n -= 2 * height * height - 2 * height + 1;
	}
	printf("%d", height - 1);
	return 0;
}
