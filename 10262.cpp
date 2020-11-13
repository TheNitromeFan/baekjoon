#include <cstdio>

int main(){
	int a1, b1, a2, b2, a3, b3, a4, b4;
	scanf("%d %d %d %d %d %d %d %d", &a1, &b1, &a2, &b2, &a3, &b3, &a4, &b4);
	int sum1 = a1 + b1 + a2 + b2, sum2 = a3 + b3 + a4 + b4;
	if(sum1 > sum2){
		printf("Gunnar");
	}else if(sum1 < sum2){
		printf("Emma");
	}else{
		printf("Tie");
	}
	return 0;
}
