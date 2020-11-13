#include <cstdio>

bool contains(int num, int digit){
	while(num){
		if(num % 10 == digit){
			return true;
		}
		num /= 10;
	}
	return false;
}

int main(){
	int n, digit;
	scanf("%d %d", &n, &digit);
	int ans = 0, cnt = 0;
	while(cnt < n){
		++ans;
		if(!contains(ans, digit)){
			++cnt;
		}
	}
	printf("%d", ans);
	return 0;
}
