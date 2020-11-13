#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		double x;
		scanf("%lf", &x);
		printf("$%.2f\n", x * 0.8);
	}
	return 0;
}
