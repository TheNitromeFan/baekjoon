#include <cstdio>
#include <cmath>


int number(int heading){
	
	int runway = heading / 10 + (heading % 10 >= 5);
	if(runway > 18) runway -= 18;
	if(runway == 0) runway = 18;
	return runway;
}

int main(void){
	
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		int h;
		scanf("%d", &h);
		printf("%02d\n", number(h));
	}
	return 0;
}
