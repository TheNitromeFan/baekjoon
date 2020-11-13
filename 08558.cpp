#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	switch(n){
		case 0:
		case 1:
			printf("1");
			break;
		case 2:
			printf("2");
			break;
		case 3:
			printf("6");
			break;
		case 4:
			printf("4");
			break;
		default:
			printf("0");
			break;
	}
	return 0;
}
