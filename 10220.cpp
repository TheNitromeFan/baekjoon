#include <cstdio>


int sequences(int n){
	
	if(n <= 3 || n == 6) return 0;
	else if(n == 4) return 2;
	else return 1;
}

int main(void){
	
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		int n;
		scanf("%d", &n);
		printf("%d\n", sequences(n));
	}
	return 0;
}
