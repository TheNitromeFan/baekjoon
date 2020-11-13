#include <cstdio>
#include <cstdlib>


long **multiply(long **a, long **b, int n, int m, int p){
	
	long **product = (long **)malloc(n * sizeof(long *));
	for(int i = 0; i < n; i++){
		*(product+i) = (long *)malloc(p * sizeof(long));
		for(int j = 0; j < p; j++){
			*(*(product+i)+j) = 0;
			for(int k = 0; k < m; k++) *(*(product+i)+j) += *(*(a+i)+k) * *(*(b+k)+j);
		}
	}
	return product;
}


int main(void){
	
	int n, m;
	scanf("%d %d", &n, &m);
	long **a = (long **)malloc(n * sizeof(long *));
	for(int i = 0; i < n; i++){
		*(a+i) = (long *)malloc(m * sizeof(long));
		for(int j = 0; j < m; j++)
			scanf("%ld", *(a+i)+j);
	}
	int p;
	scanf("%d %d", &m, &p);
	long **b = (long **)malloc(m * sizeof(long *));
	for(int i = 0; i < m; i++){
		*(b+i) = (long *)malloc(p * sizeof(long));
		for(int j = 0; j < p; j++)
			scanf("%ld", *(b+i)+j);
	}
	long **c = multiply(a, b, n, m, p);
	for(int i = 0; i < n; i++) free(*(a+i));
	free(a);
	for(int i = 0; i < m; i++) free(*(b+i));
	free(b);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < p; j++) printf("%ld ", *(*(c+i)+j));
		printf("\n");
	}
	for(int i = 0; i < n; i++) free(*(c+i));
	free(c);
	return 0;
}
