#include <cstdio>


int cycle(int n){
	
	int answer = 0;
	int m = n;
	while(1){
		int digits_sum = m / 10 + m % 10;
		m = m % 10 * 10 + digits_sum % 10;
		answer++;
		if(m == n) break;
	}
	return answer;
}

int main(void){
	
	int n;
	scanf("%d", &n);
	printf("%d", cycle(n));
	return 0;
}
