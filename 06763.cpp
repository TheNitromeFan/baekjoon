#include <cstdio>

int main(){
	int limit = 0, car = 0;
	scanf("%d %d", &limit, &car);
	if(car - limit <= 0){
		printf("Congratulations, you are within the speed limit!");
	}else if(car - limit <= 20){
		printf("You are speeding and your fine is $100.");
	}else if(car - limit <= 30){
		printf("You are speeding and your fine is $270.");
	}else{
		printf("You are speeding and your fine is $500.");
	}
	return 0;
}
