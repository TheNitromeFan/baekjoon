#include <cstdio>
#include <cmath>
#define PI acos(-1)

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int cmds;
		scanf("%d", &cmds);
		double x = 0, y = 0;
		int angle = 0;
		for(int i = 0; i < cmds; ++i){
			char cmd[3];
			int val;
			scanf(" %s %d", cmd, &val);
			if(cmd[0] == 'f'){
				x += val * cos(angle * PI / 180);
				y += val * sin(angle * PI / 180);
			}else if(cmd[0] == 'b'){
				x -= val * cos(angle * PI / 180);
				y -= val * sin(angle * PI / 180);
			}else if(cmd[0] == 'l'){
				angle += val;
			}else{
				angle -= val;
			}
		}
		double d = sqrt(x * x + y * y);
		printf("%d\n", (int)round(d));
	}
	return 0;
}
