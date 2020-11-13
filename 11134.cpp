#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n, c;
		scanf("%d %d", &n, &c);
		printf("%d\n", (n % c == 0) ? n / c : n / c + 1);
	}
	return 0;
}
