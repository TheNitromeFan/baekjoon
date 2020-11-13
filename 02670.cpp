#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	scanf("%d", &n);
	double *a = (double *)malloc(n * sizeof(double));
	for(int i = 0; i < n; ++i){
		scanf("%lf", &a[i]);
	}
	double max_ending_here = a[0];
	double max_so_far = a[0];
	for(int i = 1; i < n; ++i){
		if(max_ending_here > 1){
			max_ending_here *= a[i];
		}else{
			max_ending_here = a[i];
		}
		if(max_so_far < max_ending_here){
			max_so_far = max_ending_here;
		}
	}
	printf("%.3f", max_so_far);
	free(a);
	return 0;
}
