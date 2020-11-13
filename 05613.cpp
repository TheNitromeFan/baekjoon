#include <cstdio>

int main(){
	int n;
	scanf("%d\n", &n);
	while(true){
		char op;
		scanf("%c\n", &op);
		if(op == '='){
			break;
		}
		int m;
		scanf("%d\n", &m);
		switch(op){
			case '+':
				n += m;
				break;
			case '-':
				n -= m;
				break;
			case '*':
				n *= m;
				break;
			case '/':
				n /= m;
				break;
		}
	}
	printf("%d", n);
	return 0;
}
