#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int place = 1;
	char prev = ' ';
	for(int i = 0; i < n; ++i){
		char cur;
		scanf(" %c", &cur);
		if(prev != cur){
			++place;
		}
		prev = cur;
	}
	printf("%d", place);
	return 0;
}
