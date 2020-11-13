#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int b;
		double p;
		scanf("%d %lf", &b, &p);
		printf("%f %f %f\n", 60 * (b - 1) / p, 60 * b / p, 60 * (b + 1) / p);
	}
	return 0;
}
