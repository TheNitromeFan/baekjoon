#include <cstdio>
#include <cstdlib>

#define MAX 10000


int d(int n){
	
	int sum = n;
	while(n){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int *self_array(int limit){
	
	int *is_self = (int *)malloc(limit * sizeof(int));
	for(int i = 1; i < limit; i++) *(is_self+i) = 1;
	for(int n = 1; n < limit; n++){
		int generate = d(n);
		if(generate < limit) *(is_self+generate) = 0;
	}
	return is_self;
}

int main(void){
	
	int *self_numbers = self_array(MAX);
	for(int i = 1; i < MAX; i++)
		if(*(self_numbers+i)) printf("%d\n", i);
	free(self_numbers);
	return 0;
}
