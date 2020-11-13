#include <cstdio>

int main(){
	int n, o;
	scanf("%d %d", &n, &o);
	if(o % (n - 1) == 0){
		printf("%d %d", o + o / (n - 1) - 1, o + o / (n - 1));
	}else{
		printf("%d %d", o + o / (n - 1), o + o / (n - 1));
	}
	return 0;
}
