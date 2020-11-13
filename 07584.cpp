#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_LENGTH 21


char *to_string(char c){
	
	char *string = (char *)malloc(2 * sizeof(char));
	*string = c;
	*(string+1) = '\0';
	return string;
}

char *winner(char board[3][3]){
	
	for(int i = 0; i < 3; i++){
		if(board[i][0] != '0' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
			return to_string(board[i][0]);
		if(board[0][i] != '0' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return to_string(board[0][i]);
	}
	if(board[0][0] != '0' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
		return to_string(board[0][0]);
	if(board[2][0] != '0' && board[2][0] == board[1][1] && board[2][0] == board[0][2])
		return to_string(board[2][0]);
	char *s = (char *)malloc(5 * sizeof(char));
	strcpy(s, "Draw");
	return s;
}

char *game(char *plays, int length){
	
	char b[3][3];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) b[i][j] = '0';
	char players[3] = "XO";
	int turn = *plays == 'O';
	for(int i = 2; i < length; i += 2){
		int place = *(plays+i) - '1';
		b[place / 3][place % 3] = players[turn % 2];
		turn++;
	}
	return winner(b);
}

int main(void){
	
	char *line = (char *)malloc(MAX_LENGTH * sizeof(char));
	while(1){
		fgets(line, MAX_LENGTH, stdin);
		if(*line == '#') break;
		int len = strlen(line);
		printf("%s\n", game(line, len));
	}
	free(line);
	return 0;
}
