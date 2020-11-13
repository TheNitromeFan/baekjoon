#include <cstdio>
#include <cmath>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int tmp = (int)sqrt((a * a - b * b) * (a * a - c * c)) - b * c;
	if(tmp <= 0){
		printf("-1");
		return 0;
	}
	printf("%d", tmp / a);
	return 0;
}
