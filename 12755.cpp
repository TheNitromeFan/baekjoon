#include <cstdio>
#include <string>

int main(){
	int n;
	scanf("%d", &n);
	int total_digits = 0;
	int prev_total_digits = 0;
	int digits = 0;
	int numbers = 9;
	while(total_digits < n){
		++digits;
		prev_total_digits = total_digits;
		total_digits += digits * numbers;
		numbers *= 10;
	}
	int start = 1;
	for(int i = 0; i < digits - 1; ++i){
		start *= 10;
	}
	int idx = n - prev_total_digits - 1;
	printf("%c", std::to_string(start + idx / digits)[idx % digits]);
	return 0;
}
