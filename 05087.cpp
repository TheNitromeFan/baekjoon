#include <cstdio>

int main(){
	while(true){
		int cheryl = 0, tania = 0;
		char card[3];
		scanf("%s", card);
		if(card[0] == '#'){
			break;
		}
		do{
			switch(card[0]){
				case 'A':
				case '3':
				case '5':
				case '7':
				case '9':
					++cheryl;
					break;
				case '2':
				case '4':
				case '6':
				case '8':
				case '1':
					++tania;
					break;
			}
			scanf("%s", card);
		}while(card[0] != '*');
		if(cheryl > tania){
			printf("Cheryl\n");
		}else if(cheryl < tania){
			printf("Tania\n");
		}else{
			printf("Draw\n");
		}
	}
	return 0;
}
