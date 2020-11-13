#include <cstdio>


long cells(long n){
	
	long count = 1;
	long cells_in_shell = 1;
	while(cells_in_shell < n){
		cells_in_shell += 6*count;
		count++;
	}
	return count;
}

int main(void){
	
	long n;
	scanf("%ld", &n);
	printf("%ld", cells(n));
	return 0;
}
