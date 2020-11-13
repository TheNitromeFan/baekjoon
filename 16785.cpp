#include <cstdio>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int coins = 0;
	int days = 0;
	while(coins < c){
		++days;
		coins += a;
		if(days % 7 == 0){
			coins += b;
		}
	}
	printf("%d", days);
	return 0;
}
