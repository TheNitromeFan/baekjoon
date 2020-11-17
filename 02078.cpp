#include <cstdio>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int left = 0, right = 0;
	while(a > 1 || b > 1){
		if(a > b){
			left += (a - 1) / b;
			a = (a - 1) % b + 1;
		}else{
			right += (b - 1) / a;
			b = (b - 1) % a + 1;
		}
	}
	printf("%d %d", left, right);
	return 0;
}
