#include <cstdio>

bool compute(long long a, long long b, long long c, char op){
	bool ret = false;
	switch(op){
		case '+':
			ret = (a + b == c);
			break;
		case '-':
			ret = (a - b == c);
			break;
		case '*':
			ret = (a * b == c);
			break;
		case '/':
			ret = (a / b == c);
			break;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		long long a, b, c;
		char op;
		scanf("%lld %c %lld = %lld\n", &a, &op, &b, &c);
		if(compute(a, b, c, op)){
			printf("correct\n");
		}else{
			printf("wrong answer\n");
		}
	}
	return 0;
}
