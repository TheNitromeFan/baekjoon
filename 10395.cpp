#include <cstdio>

bool compatible(int c[][5]){
	for(int j = 0; j < 5; ++j){
		if(c[0][j] + c[1][j] != 1){
			return false;
		}
	}
	return true;
}

int main(){
	int c[2][5];
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 5; ++j){
			scanf("%d", &c[i][j]);
		}
	}
	printf("%c", compatible(c) ? 'Y' : 'N');
	return 0;
}
