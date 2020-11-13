#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int coins = -1;
	switch(n % 5){
		case 0:
			coins = n / 5;
			break;
		case 1:
			if(n >= 6){
				coins = (n - 6) / 5 + 3;
			}
			break;
		case 2:
			coins = (n - 2) / 5 + 1;
			break;
		case 3:
			if(n >= 8){
				coins = (n - 8) / 5 + 4;
			}
			break;
		case 4:
			coins = (n - 4) / 5 + 2;
			break;
	}
	printf("%d", coins);
	return 0;
}
