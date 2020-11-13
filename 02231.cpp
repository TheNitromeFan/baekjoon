#include <cstdio>


long generate(long number){
	
	long sum = number;
	while(number){
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

long smallest_generator(long number){
	long start = 0;
	if(number > 10035) start = 10026;
	else if(number > 1026) start = 1017;
	else if(number > 108) start = 103;
	else if(number > 18) start = 13;
	for(long i = start; i < number; i++){
		if(generate(i) == number) return i;
	}
	return 0;
}

int main(void){
	
	long n;
	scanf("%ld", &n);
	printf("%ld", smallest_generator(n));
	return 0;
}
