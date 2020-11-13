#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int total = 0;
	for(int i = 0; i < n; ++i){
		double length, width, height, weight;
		scanf("%lf %lf %lf %lf", &length, &width, &height, &weight);
		int allowed = (((length <= 56 && width <= 45 && height <= 25) || length + width + height <= 125) && weight <= 7) ? 1 : 0;
		printf("%d\n", allowed);
		total += allowed;
	}
	printf("%d", total);
	return 0;
}
