#include <cstdio>


int cycle(int n, int p){
	
	int a[97];
	int i = 0;
	while(1){
		a[i] = n;
		n = (a[i] * a[0]) % p;
		for(int j = 0; j < i; j++)
			if(a[j] == a[i]) return i-j;
		i++;
	}
}

int main(void){
	
	int n, p;
	scanf("%d %d", &n, &p);
	printf("%d", cycle(n, p));
	return 0;
}
