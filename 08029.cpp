#include <cstdio>
#include <cstdlib>


int max(int a, int b){
	
	if(a > b) return a;
	else return b;
}

int min(int a, int b){
	
	if(a < b) return a;
	else return b;
}

long add(long **f, int n, int x, int y, int r){
	
	long sum = 0;
	for(int i = max(x-r, 0); i <= min(x+r, n-1); i++)
		for(int j = max(y-r, 0); j <= min(y+r, n-1); j++)
			sum += *(*(f+i)+j);
	return sum;
}

long **summed_map(long **f, int n, int r){
	
	long **map = (long **)malloc(n * sizeof(long *));
	for(int i = 0; i < n; i++){
		*(map+i) = (long *)malloc(n * sizeof(long *));
		for(int j = 0; j < n; j++){
			*(*(map+i)+j) = add(f, n, i, j, r);
		}
	}
	return map;
}

int main(void){
	
	int n, r;
	scanf("%d %d", &n, &r);
	long **f = (long **)malloc(n * sizeof(long *));
	for(int i = 0; i < n; i++){
		*(f+i) = (long *)malloc(n * sizeof(long));
		for(int j = 0; j < n; j++) scanf("%ld", *(f+i)+j);
	}
	long **w = summed_map(f, n, r);
	for(int i = 0; i < n; i++){
		free(*(f+i));
		for(int j = 0; j < n; j++) printf("%ld ", *(*(w+i)+j));
		free(*(w+i));
		printf("\n");
	}
	free(f);
	free(w);
	return 0;
}
