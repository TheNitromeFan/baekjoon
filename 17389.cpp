#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	char s[10001];
	scanf("%s", s);
	int bonus = 0, score = 0;
	for(int i = 1; i <= n; ++i){
		if(s[i-1] == 'O'){
			score += i + bonus;
			++bonus;
		}else{
			bonus = 0;
		}
	}
	printf("%d", score);
	return 0;
}
