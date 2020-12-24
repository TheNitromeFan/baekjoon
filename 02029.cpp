#include <cstdio>

int main(){
	char matches[10][11];
	for(int i = 0; i < 10; ++i){
		scanf("%s", matches[i]);
	}
	bool hor[4][3], vert[3][4];
	int a = 0;
	for(int h = 0; h < 4; ++h){
		for(int v = 0; v < 3; ++v){
			hor[h][v] = matches[3 * h][3 * v + 1] == '-';
			if(!hor[h][v]){
				++a;
			}
		}
	}
	for(int h = 0; h < 3; ++h){
		for(int v = 0; v < 4; ++v){
			vert[h][v] = matches[3 * h + 1][3 * v] == '|';
			if(!vert[h][v]){
				++a;
			}
		}
	}
	int b = 0;
	for(int h = 0; h < 3; ++h){
		for(int v = 0; v < 3; ++v){
			if(hor[h][v] && hor[h + 1][v] && vert[h][v] && vert[h][v + 1]){
				++b;
			}
		}
	}
	for(int h = 0; h < 2; ++h){
		for(int v = 0; v < 2; ++v){
			if(hor[h][v] && hor[h][v + 1] && hor[h + 2][v] && hor[h + 2][v + 1]
			&& vert[h][v] && vert[h + 1][v] && vert[h][v + 2] && vert[h + 1][v + 2]){
				++b;
			}
		}
	}
	if(hor[0][0] && hor[0][1] && hor[0][2]&& hor[3][0] && hor[3][1] && hor[3][2]
	&& vert[0][0] && vert[1][0] && vert[2][0] && vert[0][3] && vert[1][3] && vert[2][3]){
		++b;
	}
	printf("%d %d", a, b);
	return 0;
}
