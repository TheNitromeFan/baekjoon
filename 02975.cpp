#include <cstdio>

int main(){
	while(true){
		int balance, amount;
		char action;
		scanf("%d %c %d\n", &balance, &action, &amount);
		if(balance == 0 && action == 'W' && amount == 0){
			break;
		}
		if(action == 'W'){
			balance -= amount;
		}else{
			balance += amount;
		}
		if(balance < -200){
			printf("Not allowed\n");
		}else{
			printf("%d\n", balance);
		}
	}
	return 0;
}
