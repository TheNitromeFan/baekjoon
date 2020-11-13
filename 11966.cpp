#include <cstdio>

bool power_of_2(int n){
	while(n > 1){
		if(n % 2 == 1){
			return false;
		}
		n /= 2;
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", power_of_2(n));
	return 0;
}
