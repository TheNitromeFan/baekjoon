#include <cstdio>

int card_index(char label){
	int ret = -1;
	switch(label){
		case 'A':
			ret = 0;
			break;
		case 'K':
			ret = 1;
			break;
		case 'Q':
			ret = 2;
			break;
		case 'J':
			ret = 3;
			break;
		case 'T':
			ret = 4;
			break;
		case '9':
			ret = 5;
			break;
		default:
			ret = 6;
			break;
	}
	return ret;
}

int main(){
	int dom[7] = {11, 4, 3, 20, 10, 14, 0}, rec[7] = {11, 4, 3, 2, 10, 0, 0};
	int n;
	char suit;
	scanf("%d %c", &n, &suit);
	char card[3];
	int points = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 4; ++j){
			scanf("%s", card);
			if(card[1] == suit){
				points += dom[card_index(card[0])];
			}else{
				points += rec[card_index(card[0])];
			}
		}
	}
	printf("%d", points);
	return 0;
}
