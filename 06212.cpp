#include <cstdio>

void count_occur(int tab[10], int x){
	while(x){
		++tab[x % 10];
		x /= 10;
	}
}

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	int occ[10] = {};
	for(int i = m; i <= n; ++i){
		count_occur(occ, i);
	}
	for(int j = 0; j < 10; ++j){
		printf("%d ", occ[j]);
	}
	return 0;
}
