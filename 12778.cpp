#include <cstdio>

char int_to_char(int x){
	return 'A' + (x - 1);
}

int char_to_int(char c){
	return c - 'A' + 1;
}

int main(){
	int t;
	scanf("%d\n", &t);
	for(int i = 0; i < t; ++i){
		int m;
		char type;
		scanf("%d %c\n", &m, &type);
		switch(type){
			case 'C':
				for(int j = 0; j < m; ++j){
					char c;
					scanf("%c ", &c);
					printf("%d ", char_to_int(c));
				}
				break;
			case 'N':
				for(int j = 0; j < m; ++j){
					int x;
					scanf("%d ", &x);
					printf("%c ", int_to_char(x));
				}
				break;
		}
		printf("\n");
	}
	return 0;
}
