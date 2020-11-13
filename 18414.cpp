#include <cstdio>

int main(){
	int x, left, right;
	scanf("%d %d %d", &x, &left, &right);
	int best;
	if(x >= right){
		best = right;
	}else if(x <= left){
		best = left;
	}else{
		best = x;
	}
	printf("%d", best);
	return 0;
}
