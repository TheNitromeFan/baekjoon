#include <cstdio>

void rotate_on_face(char face[][4], char dir){
	char tmp;
	if(dir == '+'){
		tmp = face[0][0];
		face[0][0] = face[2][0];
		face[2][0] = face[2][2];
		face[2][2] = face[0][2];
		face[0][2] = tmp;
		tmp = face[0][1];
		face[0][1] = face[1][0];
		face[1][0] = face[2][1];
		face[2][1] = face[1][2];
		face[1][2] = tmp;
	}else if(dir == '-'){
		tmp = face[0][0];
		face[0][0] = face[0][2];
		face[0][2] = face[2][2];
		face[2][2] = face[2][0];
		face[2][0] = tmp;
		tmp = face[0][1];
		face[0][1] = face[1][2];
		face[1][2] = face[2][1];
		face[2][1] = face[1][0];
		face[1][0] = tmp;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		char top[3][4], bottom[3][4], front[3][4], back[3][4], left[3][4], right[3][4];
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				top[i][j] = 'w';
				bottom[i][j] = 'y';
				front[i][j] = 'r';
				back[i][j] = 'o';
				left[i][j] = 'g';
				right[i][j] = 'b';
			}
		}
		int k;
		scanf("%d", &k);
		char move[3];
		for(int a = 0; a < k; ++a){
			scanf("%s", move);
			char tmp;
			if(move[0] == 'U'){
				rotate_on_face(top, move[1]);
				if(move[1] == '+'){
					for(int j = 0; j < 3; ++j){
						tmp = front[0][j];
						front[0][j] = right[0][j];
						right[0][j] = back[0][j];
						back[0][j] = left[0][j];
						left[0][j] = tmp;
					}
				}else if(move[1] == '-'){
					for(int j = 0; j < 3; ++j){
						tmp = front[0][j];
						front[0][j] = left[0][j];
						left[0][j] = back[0][j];
						back[0][j] = right[0][j];
						right[0][j] = tmp;
					}
				}
			}else if(move[0] == 'D'){
				rotate_on_face(bottom, move[1]);
				char tmp;
				if(move[1] == '+'){
					for(int j = 0; j < 3; ++j){
						tmp = front[2][j];
						front[2][j] = left[2][j];
						left[2][j] = back[2][j];
						back[2][j] = right[2][j];
						right[2][j] = tmp;
					}
				}else if(move[1] == '-'){
					for(int j = 0; j < 3; ++j){
						tmp = front[2][j];
						front[2][j] = right[2][j];
						right[2][j] = back[2][j];
						back[2][j] = left[2][j];
						left[2][j] = tmp;
					}
				}
			}else if(move[0] == 'F'){
				rotate_on_face(front, move[1]);
				if(move[1] == '+'){
					for(int j = 0; j < 3; ++j){
						tmp = top[2][j];
						top[2][j] = left[2 - j][2];
						left[2 - j][2] = bottom[0][2 - j];
						bottom[0][2 - j] = right[j][0];
						right[j][0] = tmp;
					}
				}else if(move[1] == '-'){
					for(int j = 0; j < 3; ++j){
						tmp = top[2][j];
						top[2][j] = right[j][0];
						right[j][0] = bottom[0][2 - j];
						bottom[0][2 - j] = left[2 - j][2];
						left[2 - j][2] = tmp;
					}
				}
			}else if(move[0] == 'B'){
				rotate_on_face(back, move[1]);
				if(move[1] == '+'){
					for(int j = 0; j < 3; ++j){
						tmp = top[0][j];
						top[0][j] = right[j][2];
						right[j][2] = bottom[2][2 - j];
						bottom[2][2 - j] = left[2 - j][0];
						left[2 - j][0] = tmp;
					}
				}else if(move[1] == '-'){
					for(int j = 0; j < 3; ++j){
						tmp = top[0][j];
						top[0][j] = left[2 - j][0];
						left[2 - j][0] = bottom[2][2 - j];
						bottom[2][2 - j] = right[j][2];
						right[j][2] = tmp;
					}
				}
			}else if(move[0] == 'L'){
				rotate_on_face(left, move[1]);
				if(move[1] == '+'){
					for(int j = 0; j < 3; ++j){
						tmp = top[j][0];
						top[j][0] = back[2 - j][2];
						back[2 - j][2] = bottom[j][0];
						bottom[j][0] = front[j][0];
						front[j][0] = tmp;
					}
				}else if(move[1] == '-'){
					for(int j = 0; j < 3; ++j){
						tmp = top[j][0];
						top[j][0] = front[j][0];
						front[j][0] = bottom[j][0];
						bottom[j][0] = back[2 - j][2];
						back[2 - j][2] = tmp;
					}
				}
			}else if(move[0] == 'R'){
				rotate_on_face(right, move[1]);
				if(move[1] == '+'){
					for(int j = 0; j < 3; ++j){
						tmp = top[j][2];
						top[j][2] = front[j][2];
						front[j][2] = bottom[j][2];
						bottom[j][2] = back[2 - j][0];
						back[2 - j][0] = tmp;
					}
				}else if(move[1] == '-'){
					for(int j = 0; j < 3; ++j){
						tmp = top[j][2];
						top[j][2] = back[2 - j][0];
						back[2 - j][0] = bottom[j][2];
						bottom[j][2] = front[j][2];
						front[j][2] = tmp;
					}
				}
			}
		}
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				printf("%c", top[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
