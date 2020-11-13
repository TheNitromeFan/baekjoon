#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int t[101], s[101];
	int maxs = -1, f = -1;
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &t[i], &s[i]);
		if(maxs < s[i]){
			maxs = s[i];
			f = i;
		}
	}
	int p = 0;
	if(s[f] == 1 || s[f] == 4){
		p = t[f] + (f - 1) * 20;
	}
	printf("%d", p);
	return 0;
}
