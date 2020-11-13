#include <cstdio>

char lights[6][40];

char digits_string[6][40] = {"###...#.###.###.#.#.###.###.###.###.###",
							 "#.#...#...#...#.#.#.#...#.....#.#.#.#.#", 
							 "#.#...#.###.###.###.###.###...#.###.###",
							 "#.#...#.#.....#...#...#.#.#...#.#.#...#",
							 "###...#.###.###...#.###.###...#.###.###"};

bool cmp(int light, int digit){
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 3; ++j){
			if(lights[i][4*light+j] == '#' && digits_string[i][4*digit+j] == '.'){
				return false;
			}
		}
	}
	return true;
}

long long power(int base, int exponent){
	if(exponent == 0){
		return 1LL;
	}
	return base * power(base, exponent-1);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 5; ++i){
		scanf("%s", lights[i]);
	}
	int digit_sums[10];
	int possibilities[10];
	long long total_possibilities = 1;
	long long total_sum = 0;
	for(int i = 0; i < n; ++i){
		digit_sums[i] = 0;
		possibilities[i] = 0;
		for(int j = 0; j < 10; ++j){
			if(cmp(i, j)){
				digit_sums[i] += j;
				++possibilities[i];
			}
		}
		if(possibilities[i]){
			total_possibilities *= possibilities[i];
		}
	}
	for(int i = 0; i < n; ++i){
		total_sum *= 10;
		if(possibilities[i]){
			total_sum += digit_sums[i] * total_possibilities / possibilities[i];
		}
	}
	printf("%lld\n", total_sum);
	double ans = total_sum / (double)total_possibilities;
	printf("%f", (ans == 0) ? -1 : ans);
	return 0;
}
