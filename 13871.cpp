#include <cstdio>

int main(){
	int n, c, s;
	scanf("%d %d %d", &n, &c, &s);
	int robot = 1;
	int cnt = 0;
	if(s == 1){
		++cnt;
	}
	for(int i = 0; i < c; ++i){
		int d;
		scanf("%d", &d);
		if(d == 1){
			++robot;
			if(robot == n + 1){
				robot = 1;
			}
		}else{
			--robot;
			if(robot == 0){
				robot = n;
			}
		}
		if(s == robot){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
