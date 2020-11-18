#include <cstdio>

void locate_heart(char oat[][1002], int n, int &row, int &col){
	for(row = 1; row + 2 < n; ++row){
		for(col = 0; col + 1 < n; ++col){
			if(oat[row][col] == '*' && oat[row][col + 1] == '*' && oat[row + 1][col] == '*'){
				return;
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	char oat[1002][1002];
	for(int i = 0; i < n; ++i){
		scanf("%s", oat[i]);
	}
	int row = 0, col = 0;
	locate_heart(oat, n, row, col);
	int leftArm = 0, rightArm = 0, torso = 0, leftLeg = 0, rightLeg = 0;
	for(int j = col - 1; j >= 0 && oat[row][j] == '*'; --j){
		++leftArm;
	}
	for(int j = col + 1; j < n && oat[row][j] == '*'; ++j){
		++rightArm;
	}
	int x;
	for(x = row + 1; oat[x][col] == '*'; ++x){
		++torso;
	}
	for(int i = x; i < n && oat[i][col - 1] == '*'; ++i){
		++leftLeg;
	}
	for(int i = x; i < n && oat[i][col + 1] == '*'; ++i){
		++rightLeg;
	}
	printf("%d %d\n%d %d %d %d %d", row + 1, col + 1, leftArm, rightArm, torso, leftLeg, rightLeg);
	return 0;
}
