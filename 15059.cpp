#include <cstdio>

int main(){
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	int ans = 0;
	if(d > a){
		ans += d - a;
	}
	if(e > b){
		ans += e - b;
	}
	if(f > c){
		ans += f - c;
	}
	printf("%d", ans);
	return 0;
}
