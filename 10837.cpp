#include <cstdio>
#include <cstdlib>
#include <algorithm>

int main(){
	int k;
	scanf("%d", &k);
	int c;
	scanf("%d", &c);
	for(int i = 0; i < c; ++i){
		int m, n;
		scanf("%d %d", &m, &n);
		int lead = abs(m - n);
		int rounds = k - std::max(m, n);
		if(m < n){
			printf("%d\n", lead - rounds <= 1);
		}else if(m > n){
			printf("%d\n", lead - rounds <= 2);
		}else{
			printf("1\n");
		}
	}
	return 0;
}
