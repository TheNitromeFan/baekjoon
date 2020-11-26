#include <cstdio>

void pos(int n, int &r, int &c){
	r = 0;
	c = 0;
	while(n > r * (r + 1) / 2){
		++r;
	}
	c = n - (r - 1) * r / 2;
}

int main(){
	while(true){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == 0 && b == 0){
			break;
		}
		if(a > b){
			int tmp = a;
			a = b;
			b = tmp;
		}
		int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
		pos(a, r1, c1);
		pos(b, r2, c2);
		int ans = r2 - r1;
		if(c2 - c1 > r2 - r1){
			ans = c2 - c1;
		}else if(c2 < c1){
			ans += c1 - c2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
