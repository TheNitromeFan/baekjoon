#include <cstdio>
#include <cstdlib>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int n, r1, c1, r2, c2;
		scanf("%d %d %d %d %d", &n, &r1, &c1, &r2, &c2);
		int r = abs(r1 - r2), c = abs(c1 - c2);
		printf("Case %d: %s\n", i, ((r == 2 && c == 1) || (r == 1 && c == 2)) ? "YES" : "NO");
	}
	return 0;
}
