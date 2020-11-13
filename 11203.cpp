#include <cstdio>

int main(){
	int h;
	scanf("%d", &h);
	char seq[35] = {};
	scanf("%s", seq);
	long long x = 1;
	for(int i = 0; seq[i] != '\0'; ++i){
		x *= 2;
		if(seq[i] == 'R'){
			++x;
		}
	}
	printf("%lld", (1LL << (h + 1)) - x);
	return 0;
}
