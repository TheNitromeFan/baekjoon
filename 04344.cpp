#include <cstdio>
#include <cstdlib>


int main(void){
	
	int c;
	scanf("%d", &c);
	for(int i = 0; i < c; i++){
		long n;
		scanf("%ld", &n);
		int *scores = (int *)malloc(n * sizeof(int));
		long total = 0;
		for(long j = 0; j < n; j++){
			scanf("%d", scores+j);
			total += *(scores+j);
		}
		int count = 0;
		for(long j = 0; j < n; j++)
			count += *(scores+j) * n > total;
		free(scores);
		printf("%.3lf%%\n", count / (double)n * 100);
	}
	return 0;
}
