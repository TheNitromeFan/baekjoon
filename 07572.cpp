#include <cstdio>

int main(){
	char letters[13] = "ABCDEFGHIJKL";
	int n;
	scanf("%d", &n);
	printf("%c%d", letters[(5 + n - 2013 + 2400) % 12], (9 + n - 2013 + 2400) % 10);
	return 0;
}
