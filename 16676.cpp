#include <cstdio>

int main(){
	int ten_powers[10] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111};
	int n;
	scanf("%d", &n);
	if(n == 0){
		printf("1");
		return 0;
	}
	int idx;
	for(idx = 0; ten_powers[idx] <= n; ++idx);
	printf("%d", idx);
	return 0;
}
