#include <cstdio>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int m, int n, int &x, int &y, int &dir){
	for(int i = 0; i < n; ++i){
		char instr[5];
		int d;
		scanf("%s %d", instr, &d);
		if(instr[0] == 'M'){
			x += dx[dir] * d;
			y += dy[dir] * d;
			if(x < 0 || x > m || y < 0 || y > m){
				return false;
			}
		}else{
			if(d){
				dir = (dir + 3) % 4;
			}else{
				dir = (dir + 1) % 4;
			}
		}
	}
	return true;
}

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	int x = 0, y = 0, dir = 0;
	if(valid(m, n, x, y, dir)){
		printf("%d %d", x, y);
	}else{
		printf("-1");
	}
	return 0;
}
