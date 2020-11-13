#include <cstdio>
#include <cstdlib>


int gcd(int a, int b){
	
	if(a < b) return gcd(b, a);
	else if(b == 0) return a;
	else return gcd(b, a % b);
}

int main(void){
	
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	scanf("%d", a);
	for(int i = 1; i < n; i++){
		scanf("%d", a+i);
		int g = gcd(*a, *(a+i));
		printf("%d/%d\n", *a/g, *(a+i)/g);
	}
	return 0;
}
