#include <cstdio>

int main(){
	int a;
	while(scanf("%d", &a) == 1){
		printf("%c\n", a % 6 == 0 ? 'Y' : 'N');
	}
	return 0;
}
