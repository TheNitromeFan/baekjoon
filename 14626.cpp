#include <cstdio>

int main(){
	char s[14];
	scanf("%s", s);
	int sum = 10000;
	int idx = 0;
	for(int i = 0; i < 13; ++i){
		if(s[i] == '*'){
			idx = i;
		}else if(i % 2){
			sum -= 3 * (s[i] - '0');
		}else{
			sum -= s[i] - '0';
		}
	}
	if(idx % 2){
		printf("%d", sum * 7 % 10);
	}else{
		printf("%d", sum % 10);
	}
	return 0;
}
