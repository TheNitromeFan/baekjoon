#include <cstdio>


long reverse(long number){
	
	long answer = 0;
	while(number){
		answer *= 10;
		answer += number % 10;
		number /= 10;
	}
	return answer;
}

int is_reflective(long number){
	
	long sum = number + reverse(number);
	return sum == reverse(sum);
}

int main(void){
	
	int t;
	scanf("%d", &t);
	long n;
	for(int i = 0; i < t; i++){
		scanf("%ld", &n);
		if(is_reflective(n)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
