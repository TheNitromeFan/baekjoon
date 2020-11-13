#include <cstdio>

int sum_of_digits(int n){
	int ret = 0;
	while(n > 0){
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main(){
	static char x[1000001];
	scanf("%s", x);
	if(x[1] == '\0'){
		printf("0\n%s", x[0] == '0' || x[0] == '3' || x[0] == '6' || x[0] == '9' ? "YES" : "NO");
		return 0;
	}
	int n = 0;
	for(int i = 0; x[i] != '\0'; ++i){
		n += x[i] - '0';
	}
	int ans = 1;
	while(n >= 10){
		++ans;
		n = sum_of_digits(n);
	}
	printf("%d\n%s", ans, n == 0 || n == 3 || n == 6 || n == 9 ? "YES" : "NO");
	return 0;
}
