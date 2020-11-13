#include <cstdio>
#include <cstdlib>

int main(){
	int l, c, n;
	scanf("%d %d %d", &l, &c, &n);
	for(int i = 0; i < c; ++i){
		int si, pi;
		scanf("%d %d", &si, &pi);
		printf("%d\n", si + abs(pi - n));
	}
	return 0;
}
