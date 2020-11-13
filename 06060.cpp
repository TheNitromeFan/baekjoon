#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int dir = 0;
	for(int i = 2; i <= n; ++i){
		int s, d, c;
		scanf("%d %d %d", &s, &d, &c);
		dir += c;
	}
	printf("%d", dir % 2);
	return 0;
}
