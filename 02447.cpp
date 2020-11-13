#include <cstdio>

bool print_white(int n, bool white, int x, int y){
	if(n == 1){
		return white;
	}else{
		return print_white(n/3, white || (x >= n/3 && x < 2*n/3 && y >= n/3 && y < 2*n/3), x % (n/3), y % (n/3));
	}
}

void print(int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%c", print_white(n, false, i, j) ? ' ' : '*');
		}
		printf("\n");
	}
}

int main(){
	int n;
	scanf("%d", &n);
	print(n);
	return 0;
}
