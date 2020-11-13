#include <cstdio>

int main(){
	int p;
	scanf("%d", &p);
	for(int i = 0; i < p; ++i){
		int n;
		double d, a, b, f;
		scanf("%d %lf %lf %lf %lf", &n, &d, &a, &b, &f);
		printf("%d %lf\n", n, d / (a + b) * f);
	}
	return 0;
}
