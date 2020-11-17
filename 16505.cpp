#include <cstdio>

bool star(int row, int col, int level){
	if(level == 0){
		return true;
	}
	if(row < (1 << (level - 1)) && col < (1 << (level - 1))){
		return star(row, col, level - 1);
	}else if(row < (1 << (level - 1))){
		return star(row, col - (1 << (level - 1)), level - 1);
	}else if(col < (1 << (level - 1))){
		return star(row - (1 << (level - 1)), col, level - 1);
	}else{
		return false;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < (1 << n); ++i){
		for(int j = 0; i + j < (1 << n); ++j){
			printf("%c", star(i, j, n) ? '*' : ' ');
		}
		printf("\n");
	}
	return 0;
}
