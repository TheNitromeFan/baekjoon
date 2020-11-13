#include <cstdio>

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	double price = x * 1000.0 / y;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &x, &y);
		double new_price = x * 1000.0 / y;
		if(new_price < price){
			price = new_price;
		}
	}
	printf("%.2lf", price);
	return 0;
}
