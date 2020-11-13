#include <cstdio>

void print_array(bool a[][20], int n){
	for(int j = 0; j < n; ++j){
		for(int i = 0; i < n; ++i){
			if(a[i][j]){
				printf("%3d", i);
			}
		}
	}
	printf("\n");
}

void rotate90(bool a[][20], int n){
	bool b[20][20] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			b[i][j] = a[n - 1 - j][i];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			a[i][j] = b[i][j];
		}
	}
}

void reflect_hor(bool a[][20], int n){
	bool b[20][20] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			b[i][j] = a[n - 1 - i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			a[i][j] = b[i][j];
		}
	}
}

void rotate270(bool a[][20], int n){
	bool b[20][20] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			b[i][j] = a[j][n - 1 - i];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			a[i][j] = b[i][j];
		}
	}
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		bool a[20][20] = {};
		for(int j = 0; j < n; ++j){
			int i;
			scanf("%d", &i);
			a[i][j] = true;
		}
		for(int r = 0; r < 4; ++r){
			print_array(a, n);
			rotate270(a, n);
		}
		reflect_hor(a, n);
		for(int r = 0; r < 4; ++r){
			print_array(a, n);
			rotate270(a, n);
		}
		printf("\n");
	}
	return 0;
}
