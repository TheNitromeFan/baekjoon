#include <cstdio>

bool correct(int a, int b, int c, char op){
	if(op == '+'){
		return a + b == c;
	}else{
		return a - b == c;
	}
}

int main(){
	int t;
	scanf("%d\n", &t);
	for(int i = 1; i <= t; ++i){
		int a, b, c;
		char op;
		scanf("%d %c %d = %d\n", &a, &op, &b, &c);
		printf("Case %d: %s\n", i, correct(a, b, c, op) ? "YES" : "NO");
	}
	return 0;
}
