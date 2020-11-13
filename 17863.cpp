#include <cstdio>

int main(){
	char s[8];
	scanf("%s", s);
	printf("%s", (s[0] == '5' && s[1] == '5' && s[2] == '5') ? "YES" : "NO");
	return 0;
}
