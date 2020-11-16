#include <cstdio>

int basket(int n, int k){
	if(n < k * (k + 1) / 2){
		return -1;
	}
	return (n - k * (k + 1) / 2) % k == 0 ? k - 1 : k;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", basket(n, k));
	return 0;
}
