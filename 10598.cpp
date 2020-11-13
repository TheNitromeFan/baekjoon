#include <cstdio>
#include <cstdlib>

int pos(int a, int b, int t){
	t %= 2 * abs(b - a);
	if(a <= b && t <= b - a){
		return a + t;
	}else if(a <= b){
		return b - (t - b + a);
	}else if(a > b && t <= a - b){
		return a - t;
	}else{
		return b + (t - a + b);
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[1000], b[1000];
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &a[i], &b[i]);
	}
	for(int j = 0; j < m; ++j){
		int x, y, t;
		scanf("%d %d %d", &x, &y, &t);
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			int car = pos(a[i], b[i], t);
			if(car >= x && car <= y){
				++cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
