#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		double a;
		scanf("%lf", &a);
		printf("%.10lf\n", a / 6);
	}
	return 0;
}
