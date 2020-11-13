#include <cstdio>

int main(){
	int a, b, c, d, s;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &s);
	int nikky = 0;
	for(int i = 0; i < s; ++i){
		if(i % (a + b) < a){
			++nikky;
		}else{
			--nikky;
		}
	}
	int byron = 0;
	for(int i = 0; i < s; ++i){
		if(i % (c + d) < c){
			++byron;
		}else{
			--byron;
		}
	}
	if(nikky > byron){
		printf("Nikky");
	}else if(nikky < byron){
		printf("Byron");
	}else{
		printf("Tied");
	}
	return 0;
}
