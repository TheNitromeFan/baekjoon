#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	static char s[1000001];
	scanf("%s", s);
	for(int i = n - 1; i > 0; --i){
		if((s[i - 1] == 'A' && s[i] == 'G') || (s[i - 1] == 'G' && s[i] == 'A')
		|| (s[i - 1] == 'C' && s[i] == 'C')){
			s[i - 1] = 'C';
		}else if((s[i - 1] == 'G' && s[i] == 'C') || (s[i - 1] == 'C' && s[i] == 'G')
		|| (s[i - 1] == 'T' && s[i] == 'T')){
			s[i - 1] = 'T';
		}else if((s[i - 1] == 'A' && s[i] == 'A') || (s[i - 1] == 'A' && s[i] == 'C')
		|| (s[i - 1] == 'G' && s[i] == 'T') || (s[i - 1] == 'C' && s[i] == 'A')
		|| (s[i - 1] == 'T' && s[i] == 'G')){
			s[i - 1] = 'A';
		}else{
			s[i - 1] = 'G';
		}
	}
	printf("%c", s[0]);
	return 0;
}
