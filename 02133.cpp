#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	if(n % 2 == 1){
		printf("0");
		return 0;
	}
	int a[31] = {};
	a[0] = 1;
	for(int i = 2; i <= n; i += 2){
		a[i] = 3 * a[i-2];
		for(int j = i-4; j >= 0; j -= 2){
			a[i] += 2 * a[j];
		}
	}
	printf("%d", a[n]);
	return 0;
}
