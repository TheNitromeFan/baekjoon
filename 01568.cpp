#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0, birds = 0;
	while(n > 0){
		++birds;
		if(n < birds){
			birds = 1;
		}
		n -= birds;
		++ans;
	}
	printf("%d", ans);
	return 0;
}
