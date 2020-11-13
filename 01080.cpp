#include <cstdio>

void change_submatrix(char a[][51], int startx, int starty){
	for(int i = startx; i < startx + 3; ++i){
		for(int j = starty; j < starty + 3; ++j){
			a[i][j] = (a[i][j] == '0') ? '1' : '0';
		}
	}
}

bool check_equal(char a[][51], char b[][51], int n, int m){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(a[i][j] != b[i][j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char a[51][51], b[51][51];
	for(int i = 0; i < n; ++i){
		scanf("%s", a[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%s", b[i]);
	}
	int cnt = 0;
	for(int i = 0; i < n-2; ++i){
		for(int j = 0; j < m-2; ++j){
			if(a[i][j] != b[i][j]){
				change_submatrix(a, i, j);
				++cnt;
			}
		}
	}
	printf("%d", check_equal(a, b, n, m) ? cnt : -1);
	return 0;
}
