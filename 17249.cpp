#include <cstdio>

int main(){
	char s[1002];
	fgets(s, 1001, stdin);
	int count = 0;
	int i;
	for(i = 0; s[i] != '^'; ++i){
		if(s[i] == '@'){
			++count;
		}
	}
	printf("%d ", count);
	++i;
	for(; s[i] != ')'; ++i);
	count = 0;
	for(; s[i] != '\0'; ++i){
		if(s[i] == '@'){
			++count;
		}
	}
	printf("%d", count);
	return 0;
}
