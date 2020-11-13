#include <cstdio>
#include <cstdlib>


int compare(const void *a, const void *b){
	
	return *(int *)a - *(int *)b;
}

double mean(int *numbers, long n){
	
	long total = 0;
	for(long i = 0; i < n; i++) total += *(numbers+i);
	return total / (double)n;
}

int median(int *numbers, long n){
	
	qsort(numbers, n, sizeof(int), compare);
	return *(numbers+(n-1)/2);
}

int mode(int *numbers, long n){
	
	int count[8001] = {0};
	for(long i = 0; i < n; i++) count[*(numbers+i)+4000]++;
	int max_count = 0;
	for(int i = -4000; i <= 4000; i++){
		if(count[i+4000] > max_count) max_count = count[i+4000];
	}
	int answer = -4001;
	for(int i = -4000; i <= 4000; i++){
		if(count[i+4000] == max_count && answer == -4001) answer = i;
		else if(count[i+4000] == max_count) return i;
	}
	return answer;
}

int range(int *numbers, long n){
	
	int max = -4000, min = 4000;
	for(long i = 0; i < n; i++){
		if(*(numbers+i) > max) max = *(numbers+i);
		if(*(numbers+i) < min) min = *(numbers+i);
	}
	return max - min;
}

int main(void){
	
	long n;
	scanf("%ld", &n);
	int *numbers = (int *)malloc(n * sizeof(int));
	for(long i = 0; i < n; i++) scanf("%d", numbers+i);
	printf("%.0lf\n", mean(numbers, n));
	printf("%d\n", median(numbers, n));
	printf("%d\n", mode(numbers, n));
	printf("%d\n", range(numbers, n));
	free(numbers);
	return 0;
}
