#include <cstdio>
#include <algorithm>

using std::min;

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n, p;
		scanf("%d %d", &n, &p);
		int a[4] = {};
		for(int i = 0; i < n; ++i){
			int x;
			scanf("%d", &x);
			++a[x % p];
		}
		int groups = 0;
		if(p == 4){
			int y = min(a[1], a[3]);
			groups += a[0] + a[2] / 2 + y;
			a[0] = 0;
			a[2] %= 2;
			a[1] -= y;
			a[3] -= y;
			if(a[2] == 1 && a[1] >= 2){
				++groups;
				a[2] = 0;
				a[1] -= 2;
			}else if(a[2] == 1 && a[3] >= 2){
				++groups;
				a[2] = 0;
				a[3] -= 2;
			}
			groups += a[1] / 4 + a[3] / 4;
			a[1] %= 4;
			a[3] %= 4;
			if(a[1] > 0 || a[2] > 0 || a[3] > 0){
				++groups;
			}
		}else if(p == 3){
			int y = min(a[1], a[2]);
			groups += a[0] + y;
			a[0] = 0;
			a[1] -= y;
			a[2] -= y;
			groups += a[1] / 3 + a[2] / 3;
			a[1] %= 3;
			a[2] %= 3;
			if(a[1] > 0 || a[2] > 0){
				++groups;
			}
		}else{
			groups += a[0] + a[1] / 2;
			a[0] = 0;
			a[1] %= 2;
			if(a[1] > 0){
				++groups;
			}
		}
		printf("Case #%d: %d\n", a0, groups);
	}
	return 0;
}
