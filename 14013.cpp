#include <cstdio>

int main(){
	double x, y;
	scanf("%lf %lf", &x, &y);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		double z;
		char q;
		scanf("%lf %c", &z, &q);
		if(q == 'A'){
			printf("%f\n", z * y / x);
		}else{
			printf("%f\n", z * x / y);
		}
	}
	return 0;
}
