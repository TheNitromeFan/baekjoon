#include <cstdio>

int main(){
	int a, t, type;
	scanf("%d %d %d", &a, &t, &type);
	int index = 0;
	int b = 0, d = 0;
	for(int stage = 1; ; ++stage){
		for(int i = 0; i < 2; ++i){
			++b;
			if(type == 0 && b == t){
				printf("%d", index);
				return 0;
			}
			index = (index + 1) % a;
			++d;
			if(type == 1 && d == t){
				printf("%d", index);
				return 0;
			}
			index = (index + 1) % a;
		}
		for(int j = 0; j <= stage; ++j){
			++b;
			if(type == 0 && b == t){
				printf("%d", index);
				return 0;
			}
			index = (index + 1) % a;
		}
		for(int j = 0; j <= stage; ++j){
			++d;
			if(type == 1 && d == t){
				printf("%d", index);
				return 0;
			}
			index = (index + 1) % a;
		}
	}
	return 0;
}
