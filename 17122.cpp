#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		char square[3];
		int num;
		scanf("%s %d", square, &num);
		char new_row = (num - 1) / 8 + '1';
		char new_col = (num - 1) % 8 + 'A';
		printf("%s\n", abs(new_row - square[0]) % 2 == abs(new_col - square[1]) % 2 ? "YES" : "NO");
	}
	return 0;
}
