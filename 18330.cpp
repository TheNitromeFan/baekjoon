#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	k += 60;
	int cost;
	if(k > n){
		cost = 1500 * n;
	}else{
		cost = 1500 * k + 3000 * (n - k);
	}
	printf("%d", cost);
	return 0;
}
