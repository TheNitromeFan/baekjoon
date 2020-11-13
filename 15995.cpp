#include <cstdio>

int inverse(int a, int m){
	for(int i = 1; i < m; ++i){
		if(a * i % m == 1){
			return i;
		}
	}
	return -1;
}

int main(){
	int a, m;
	scanf("%d %d", &a, &m);
	printf("%d", inverse(a, m));
	return 0;
}
