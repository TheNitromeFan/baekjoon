#include <cstdio>

int main(){
	int d;
	scanf("%d", &d);
	if(d % 2 == 1){
		int n1 = (d - 1) / 2;
		int n2 = n1 + 1;
		printf("%d %d", n1, n2);
	}else if(d % 4 == 0){
		int n1 = (d - 4) / 4;
		int n2 = n1 + 2;
		printf("%d %d", n1, n2);
	}else{
		printf("impossible");
	}
	return 0;
}
