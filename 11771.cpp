#include <cstdio>

void rotate(char g[][11], int n){
	char h[11][11];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			h[i][j] = g[n - 1 - j][i];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			g[i][j] = h[i][j];
		}
	}
}

bool valid_grill(char g[][11], int n){
	int holes = 0;
	bool board[11][11] = {};
	for(int a0 = 0; a0 < 4; ++a0){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(g[i][j] == '.'){
					if(board[i][j]){
						return false;
					}
					++holes;
					board[i][j] = true;
				}
			}
		}
		rotate(g, n);
	}
	return holes == n * n;
}

int main(){
	int n;
	scanf("%d", &n);
	char g[11][11];
	for(int i = 0; i < n; ++i){
		scanf("%s", g[i]);
	}
	if(!valid_grill(g, n)){
		printf("invalid grille");
		return 0;
	}
	char s[101];
	scanf("%s", s);
	int index = 0;
	char board[11][11];
	for(int a0 = 0; a0 < 4; ++a0){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(g[i][j] == '.'){
					board[i][j] = s[index];
					++index;
				}
			}
		}
		rotate(g, n);
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%c", board[i][j]);
		}
	}
	return 0;
}
