#include <cstdio>

int ancestor(int a, int b){
	if(a == b){
		return a;
	}else if(a > b){
		return ancestor(b, a);
	}else{
		return ancestor(b / 2, a);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", 10 * ancestor(a, b));
	}
	return 0;
}
