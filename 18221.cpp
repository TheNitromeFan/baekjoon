#include <cstdio>
#include <algorithm>

using std::min;
using std::max;

bool escape(int desks[][1000], int a, int b, int c, int d){
	if((a - c) * (a - c) + (b - d) * (b - d) < 5 * 5){
		return false;
	}
	int cnt = 0;
	for(int i = min(a, c); i <= max(a, c); ++i){
		for(int j = min(b, d); j <= max(b, d); ++j){
			if(desks[i][j] == 1){
				++cnt;
			}
		}
	}
	return cnt >= 3;
}

int main(){
	static int desks[1000][1000];
	int n;
	scanf("%d", &n);
	int a = 0, b = 0, c = 0, d = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &desks[i][j]);
			if(desks[i][j] == 5){
				c = i;
				d = j;
			}else if(desks[i][j] == 2){
				a = i;
				b = j;
			}
		}
	}
	printf("%d", escape(desks, a, b, c, d));
	return 0;
}
