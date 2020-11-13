#include <cstdio>

bool bingo(bool b[][5]){
	int lines = 0;
	for(int i = 0; i < 5; ++i){
		if(b[i][0] && b[i][1] && b[i][2] && b[i][3] && b[i][4]){
			++lines;
		}
		if(b[0][i] && b[1][i] && b[2][i] && b[3][i] && b[4][i]){
			++lines;
		}
	}
	if(b[0][0] && b[1][1] && b[2][2] && b[3][3] && b[4][4]){
		++lines;
	}
	if(b[0][4] && b[1][3] && b[2][2] && b[3][1] && b[4][0]){
		++lines;
	}
	return lines >= 3;
}

int main(){
	int numbers[26][2];
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			int tmp;
			scanf("%d", &tmp);
			numbers[tmp][0] = i;
			numbers[tmp][1] = j;
		}
	}
	bool board[5][5] = {};
	int i = 0;
	for(i = 1; i <= 25; ++i){
		int next;
		scanf("%d", &next);
		board[numbers[next][0]][numbers[next][1]] = true;
		if(bingo(board)){
			break;
		}
	}
	printf("%d", i);
	return 0;
}
