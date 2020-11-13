#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	if(n != m + 1){
		printf("No");
		return 0;
	}
	int skip = 0;
	int p = -1;
	for(int i = 1; i <= m; ++i){
		int x;
		scanf("%d", &x);
		if(i + skip != x){
			++skip;
			if(skip > 1 || i + skip != x){
				printf("No");
				return 0;
			}else{
				p = i;
			}
		}
	}
	if(skip == 0){
		p = n;
	}
	printf("Yes\n%d", p);
	return 0;
}
