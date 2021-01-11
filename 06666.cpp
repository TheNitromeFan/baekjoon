#include <cstdio>

int main(){
	char board[17][34];
	for(int i = 0; i < 17; ++i){
		scanf("%s", board[i]);
	}
	char whitePieces[7] = "KQRBNP", blackPieces[7] = "kqrbnp";
	printf("White: ");
	bool started = false;
	for(int i = 0; i < 6; ++i){
		for(int r = 1; r <= 8; ++r){
			for(char c = 'a'; c <= 'h'; ++c){
				if(board[17 - 2 * r][2 + 4 * (c - 'a')] == whitePieces[i]){
					if(!started){
						started = true;
					}else{
						printf(",");
					}
					if(i != 5){
						printf("%c", whitePieces[i]);
					}
					printf("%c%d", c, r);
				}
			}
		}
	}
	printf("\nBlack: ");
	started = false;
	for(int i = 0; i < 6; ++i){
		for(int r = 8; r >= 1; --r){
			for(char c = 'a'; c <= 'h'; ++c){
				if(board[17 - 2 * r][2 + 4 * (c - 'a')] == blackPieces[i]){
					if(!started){
						started = true;
					}else{
						printf(",");
					}
					if(i != 5){
						printf("%c", blackPieces[i] - 'a' + 'A');
					}
					printf("%c%d", c, r);
				}
			}
		}
	}
	return 0;
}
