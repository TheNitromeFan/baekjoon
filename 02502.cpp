#include <cstdio>
#include <cstdlib>


long *fibonacci(int terms){
	
	long *fibs = (long *)malloc((terms+1) * sizeof(long));
	*fibs = 0;
	*(fibs+1) = 1;
	for(int i = 2; i <= terms; i++)
		*(fibs+i) = *(fibs+i-1) + *(fibs+i-2);
	return fibs;
}

long *initials(int day, long number){
	
	long *fibs = fibonacci(day);
	long *answer = (long *)malloc(2 * sizeof(long));
	for(long b = (number-1) / *(fibs+day) + 1; b <= (number - *(fibs+day-2)) / *(fibs+day-1); b++)
		if((number - *(fibs+day-1) * b) % *(fibs+day-2) == 0){
			*answer = (number - *(fibs+day-1) * b) / *(fibs+day-2);
			*(answer+1) = b;
		}
	free(fibs);
	return answer;
}

int main(void){
	
	int d;
	long k;
	scanf("%d %ld", &d, &k);
	long *answer = initials(d, k);
	printf("%ld\n%ld", *answer, *(answer+1));
	free(answer);
	return 0;
}
