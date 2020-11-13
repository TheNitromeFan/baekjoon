#include <cstdio>

int diff(int a, int b, int c){
	if(a == b){
		return c;
	}else if(a == c){
		return b;
	}else{
		return a;
	}
}

int main(){
	int coor[3][2];
	for(int i = 0; i < 3; ++i){
		scanf("%d %d", &coor[i][0], &coor[i][1]);
	}
	printf("%d %d", diff(coor[0][0], coor[1][0], coor[2][0]), diff(coor[0][1], coor[1][1], coor[2][1]));
	return 0;
}
