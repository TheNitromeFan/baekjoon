#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int lies = 0;
	for(int i = 0; i < n; ++i){
		char s[7];
		scanf("%s", s);
		if(s[0] == 'L'){
			++lies;
		}
	}
	printf("%s", lies % 2 == 0 ? "TRUTH" : "LIE");
	return 0;
}
