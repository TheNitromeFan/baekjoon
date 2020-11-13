#include <cstdio>

int main(){
	int d;
	scanf("%d", &d);
	printf("%d", (d % 5 == 0) ? d / 5 : d / 5 + 1);
	return 0;
}
