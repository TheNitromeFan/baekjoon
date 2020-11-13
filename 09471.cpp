#include <cstdio>
#include <cstdlib>


long pisano(long number){
	
	long a = 1, b = 1, count = 0;
	do{
		long temp = (a + b) % number;
		a = b;
		b = temp;
		count++;
	}while(a != 1 || b != 1);
	return count;
}

int main(void){
	
	int p;
	scanf("%d", &p);
	for(int i = 0; i < p; i++){
		int n;
		long m;
		scanf("%d %ld", &n, &m);
		printf("%d %ld\n", n, pisano(m));
	}
	return 0;
}
