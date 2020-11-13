#include <cstdio>
#include <algorithm>

using std::max;

int main(){
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	int boxes = 0;
	boxes += r / 3;
	r %= 3;
	boxes += g / 3;
	g %= 3;
	boxes += b / 3;
	b %= 3;
	if(r == 0 && g == 0 && b == 0);
	else if((r == 0 || r == 1) && (g == 0 || g == 1) && (b == 0 || b == 1)){
		boxes += 1;
	}else if((r > 0 && g > 0) || (g > 0 && b > 0) || (b > 0 && r > 0)){
		boxes += 2;
	}else if(r > 0 || g > 0 || b > 0){
		boxes += 1;
	}
	printf("%d", boxes);
	return 0;
}
