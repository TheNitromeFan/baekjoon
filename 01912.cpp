#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int max_ending_here = a[0];
	int max_so_far = a[0];
	for(int i = 1; i < n; ++i){
		if(max_ending_here > 0){
			max_ending_here += a[i];
		}else{
			max_ending_here = a[i];
		}
		if(max_so_far < max_ending_here){
			max_so_far = max_ending_here;
		}
	}
	printf("%d", max_so_far);
	free(a);
	return 0;
}
