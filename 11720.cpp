#include <cstdio>


int sum(int n, char s[101]){
	
	int total = 0;
	for(int i = 0; i < n; i++)
		total += s[i] - '0';
	return total;
}

int main(void){
	
	int n;
	scanf("%d", &n);
	char s[101];
	scanf("%s", s);
	printf("%d", sum(n, s));
	return 0;
}
