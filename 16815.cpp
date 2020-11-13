#include <cstdio>
#include <cstdlib>
#include <cassert>

int main(){
	char s[101];
	scanf("%s", s);
	int idx = 0;
	for(int i = 0; s[i] != '\0'; ++i){
		if(s[i] == '*'){
			idx = i;
			break;
		}
	}
	int left = 0, right = 0;
	for(int i = idx - 1; i >= 0; --i){
		if(s[i] == '('){
			++left;
		}else{
			--left;
		}
	}
	for(int i = idx + 1; s[i] != '\0'; ++i){
		if(s[i] == ')'){
			++right;
		}else{
			--right;
		}
	}
	assert(left == right);
	printf("%d", left);
	return 0;
}
