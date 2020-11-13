#include <cstdio>
int main(){
	int n;
	scanf("%d", &n);
	int row, col, diag1, diag2;
	scanf("%d %d %d %d", &row, &col, &diag1, &diag2);
	// y = row
	// x = col
	// x + y = diag1 + 1
	// x - y = diag2 - n
	// inclusion-exclusion
	int gray = 0, white = 0;
	gray += n / 2;
	white += n / 2;
	if(n % 2 == 1){
		if(row % 2 == 1){
			++gray;
		}else{
			++white;
		}
	}
	gray += n / 2;
	white += n / 2;
	if(n % 2 == 1){
		if(col % 2 == 1){
			++gray;
		}else{
			++white;
		}
	}
	if(diag1 <= n){
		if(diag1 % 2 == 1){
			gray += diag1;
		}else{
			white += diag1;
		}
	}else{
		if(diag1 % 2 == 1){
			gray += 2 * n - diag1;
		}else{
			white += 2 * n - diag1;
		}
	}
	if(diag2 <= n){
		if((diag2 + n) % 2 == 0){
			gray += diag2;
		}else{
			white += diag2;
		}
	}else{
		if((diag2 + n) % 2 == 0){
			gray += 2 * n - diag2;
		}else{
			white += 2 * n - diag2;
		}
	}
	// printf("%d %d\n", gray, white);
	if((row + col) % 2 == 0){
		--gray;
	}else{
		--white;
	}
	if(diag1 - row + 1 >= 1 && diag1 - row + 1 <= n){
		if(diag1 % 2 == 1){
			--gray;
		}else{
			--white;
		}
	}
	if(diag1 - col + 1 >= 1 && diag1 - col + 1 <= n){
		if(diag1 % 2 == 1){
			--gray;
		}else{
			--white;
		}
	}
	if(diag2 + row - n >= 1 && diag2 + row - n <= n){
		if((diag2 + n) % 2 == 0){
			--gray;
		}else{
			--white;
		}
	}
	if(col - diag2 + n >= 1 && col - diag2 + n <= n){
		if((diag2 + n) % 2 == 0){
			--gray;
		}else{
			--white;
		}
	}
	if(diag1 % 2 != (diag2 + n) % 2 && (diag1 + diag2 - n + 1) / 2 >= 1 && (diag1 + diag2 - n + 1) / 2 <= n
	&& (diag1 - diag2 + n + 1) / 2 >= 1 && (diag1 - diag2 + n + 1) / 2 <= n){
		if(diag1 % 2 == 1){
			--gray;
		}else{
			--white;
		}
	}
	// printf("%d %d\n", gray, white);
	if(row + col == diag1 + 1){
		if(diag1 % 2 == 1){
			++gray;
		}else{
			++white;
		}
	}
	if(col - row == diag2 - n){
		if((diag2 + n) % 2 == 0){
			++gray;
		}else{
			++white;
		}
	}
	if(diag1 + 1 - row == row + diag2 - n && diag1 + 1 - row >= 1 && diag1 + 1 - row <= n){
		if(diag1 % 2 == 1){
			++gray;
		}else{
			++white;
		}
	}
	if(diag1 + 1 - col == col - diag2 + n && diag1 + 1 - col >= 1 && diag1 + 1 - col <= n){
		if(diag1 % 2 == 1){
			++gray;
		}else{
			++white;
		}
	}
	if(row + col == diag1 + 1 && col - row == diag2 - n){
		if(diag1 % 2 == 1){
			--gray;
		}else{
			--white;
		}
	}
	printf("%d\n%d %d", gray + white, gray, white);
	return 0;
}
