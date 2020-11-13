#include <cstdio>

int main(){
	int a, b, c, d, p, m, n;
	scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &p, &m, &n);
	int ans;
	ans = 0;
	if(p % (a + b) >= 1 && p % (a + b) <= a){
		++ans;
	}
	if(p % (c + d) >= 1 && p % (c + d) <= c){
		++ans;
	}
	printf("%d\n", ans);
	ans = 0;
	if(m % (a + b) >= 1 && m % (a + b) <= a){
		++ans;
	}
	if(m % (c + d) >= 1 && m % (c + d) <= c){
		++ans;
	}
	printf("%d\n", ans);
	ans = 0;
	if(n % (a + b) >= 1 && n % (a + b) <= a){
		++ans;
	}
	if(n % (c + d) >= 1 && n % (c + d) <= c){
		++ans;
	}
	printf("%d\n", ans);
	return 0;
}
