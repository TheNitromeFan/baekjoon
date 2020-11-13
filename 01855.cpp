#include <cstdio>

int main(){
	char t[200][21] = {};
	int k;
	scanf("%d", &k);
	char line[201];
	scanf("%s", line);
	int row = 0, col = 0;
	for(int i = 0; line[i] != '\0'; ++i){
		t[row][col] = line[i];
		if((row % 2 == 0 && col == k - 1) || (row % 2 == 1 && col == 0)){
			++row;
		}else if(row % 2 == 0){
			++col;
		}else if(row % 2 == 1){
			--col;
		}
	}
	for(int j = 0; j < k; ++j){
		for(int i = 0; t[i][j] != 0; ++i){
			printf("%c", t[i][j]);
		}
	}
	return 0;
}
