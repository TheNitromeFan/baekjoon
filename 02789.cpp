#include <cstdio>
#include <cstring>

int main(){
	char s[101];
	scanf("%s", s);
	int n = strlen(s);
	char banned[10] = "CAMBRIDGE";
	bool flag;
	for(int i = 0; i < n; ++i){
		flag = false;
		for(int j = 0; j < 9; ++j){
			if(s[i] == banned[j]){
				flag = true;
			}
		}
		if(!flag){
			printf("%c", s[i]);
		}
	}
	return 0;
}
