#include <cstdio>

int main(){
	int d, vf, vg;
	while(scanf("%d %d %d", &d, &vf, &vg) == 3){
		printf("%c\n", (12 * 12 * vg * vg >= 12 * 12 * vf * vf + d * d * vf * vf) ? 'S' : 'N');
	}
	return 0;
}
