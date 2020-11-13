#include <cstdio>
#include <cstdlib>


int *digit_count(long number){
	
	int *digits = (int *)malloc(10 * sizeof(int));
	for(int i = 0; i < 10; i++) *(digits+i) = 0;
	while(number){
		++*(digits+number%10);
		number /= 10;
	}
	return digits;
}

int sets(long number){
	
	int *digits = digit_count(number);
	int sum_of_six_and_nine = *(digits+6) + *(digits+9);
	*(digits+6) = (sum_of_six_and_nine + 1) / 2;
	*(digits+9) = sum_of_six_and_nine / 2;
	int max = 1;
	for(int i = 0; i < 9; i++)
		if(*(digits+i) > max) max = *(digits+i);
	free(digits);
	return max;
}


int main(){
	
	long n;
	scanf("%ld", &n);
	printf("%d", sets(n));
	return 0;
}
