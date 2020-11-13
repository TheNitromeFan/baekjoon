#include <cstdio>

int main(){
	int a1, b1, a2, b2, x1, y1, x2, y2;
	scanf("%d %d %d %d\n%d %d %d %d", &a1, &b1, &a2, &b2, &x1, &y1, &x2, &y2);
	if(a2 < x1 || b2 < y1 || x2 < a1 || y2 < b1){
		printf("NULL");
	}else if((a2 == x1 && b2 == y1) || (a2 == x1 && b1 == y2)
	|| (a1 == x2 && b2 == y1) || (a1 == x2 && b1 == y2)){
		printf("POINT");
	}else if(a2 == x1 || b2 == y1 || a1 == x2 || b1 == y2){
		printf("LINE");
	}else{
		printf("FACE");
	}
	return 0;
}
