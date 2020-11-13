#include <cstdio>

int main(){
	int s, m, ell;
	scanf("%d %d %d", &s, &m, &ell);
	int score = s + 2 * m + 3 * ell;
	printf("%s", (score >= 10) ? "happy" : "sad");
	return 0;
}
