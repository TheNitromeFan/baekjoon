#include <cstdio>
#include <cstdlib>

void find_pos(int n, int &x, int &y){
	x = 0;
	y = 0;
	int i = 1;
	while(i * i < n){
		i += 2;
		--x;
		--y;
	}
	int m = i * i;
	if(m == n){
		return;
	}
	while(true){
		for(int j = 0; j < i - 1; ++j){
			--m;
			++y;
			if(m == n){
				return;
			}
		}
		for(int j = 0; j < i - 1; ++j){
			--m;
			++x;
			if(m == n){
				return;
			}
		}
		for(int j = 0; j < i - 1; ++j){
			--m;
			--y;
			if(m == n){
				return;
			}
		}
		for(int j = 0; j < i - 2; ++j){
			--m;
			--x;
			if(m == n){
				return;
			}
		}
	}
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int x1, y1, x2, y2;
	find_pos(a, x1, y1);
	find_pos(b, x2, y2);
	printf("%d", abs(x1 - x2) + abs(y1 - y2));
	return 0;
}
