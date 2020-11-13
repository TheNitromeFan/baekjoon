#include <cstdio>

int main(){
	while(true){
		int rabbit;
		scanf("%d", &rabbit);
		if(rabbit == 0){
			break;
		}
		int low = 1, high = 50;
		while(true){
			int card = (low + high) / 2;
			printf("%d ", card);
			if(card == rabbit){
				break;
			}else if(card > rabbit){
				high = card - 1;
			}else{
				low = card + 1;
			}
		}
		printf("\n");
	}
	return 0;
}
