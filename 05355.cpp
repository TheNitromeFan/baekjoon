#include <cstdio>
#include <cstring>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		double x;
		scanf("%lf", &x);
		char ops[105];
		fgets(ops, 100, stdin);
		int len = strlen(ops);
		for(int i = 1; i < len; i += 2){
			if(ops[i] == '@'){
				x *= 3;
			}else if(ops[i] == '%'){
				x += 5;
			}else if(ops[i] == '#'){
				x -= 7;
			}
		}
		printf("%.2f\n", x);
	}
	return 0;
}
