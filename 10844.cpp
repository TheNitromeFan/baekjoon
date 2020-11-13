#include <cstdio>

#define mod 1000000000


long long stair_numbers(int number){
	
	if(number == 1) return 9;
	long long digits_and_start[101][10];
	for(int j = 1; j <= 9; j++) digits_and_start[1][j] = 1;
	long long total = 0;
	for(int i = 2; i <= number; i++)
		for(int j = 1; j <= 9; j++){
			if(i == 2 && j == 1)
				digits_and_start[2][1] = 2;
			else if(j == 1)
				digits_and_start[i][1] = (digits_and_start[i-2][1] + digits_and_start[i-1][2]) % mod;
			else if(j == 9)
				digits_and_start[i][9] = digits_and_start[i-1][8];
			else
				digits_and_start[i][j] = (digits_and_start[i-1][j-1] + digits_and_start[i-1][j+1]) % mod;
		}
	for(int j = 1; j <= 9; j++){
		total += digits_and_start[number][j];
		total %= mod;
	}
	return total;
}

int main(void){
	
	int n;
	scanf("%d", &n);
	printf("%lld", stair_numbers(n));
	return 0;
}
