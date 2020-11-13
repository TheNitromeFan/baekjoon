#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	bool held = false;
	for(int i = 0; i < n; ++i){
		double x;
		scanf("%lf", &x);
		int y = (int)x;
		if(x != y && !held){
			held = true;
			++cnt;
		}else if(y > 0 && !held){
			held = true;
		}
		cnt += y;
	}
	printf("%d", cnt);
	return 0;
}
