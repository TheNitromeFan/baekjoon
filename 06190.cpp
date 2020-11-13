#include <cstdio>

int main(){
	long long n;
	scanf("%lld", &n);
	int score = 0;
	while(n > 1){
		if(n % 2 == 1){
			n = (3 * n + 1) / 2;
			score += 2;
		}else{
			n /= 2;
			++score;
		}
	}
	printf("%d", score);
	return 0;
}
