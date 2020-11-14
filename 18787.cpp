#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	char cow1[1001], cow2[1001];
	scanf("%s %s", cow1, cow2);
	int cnt = 0;
	int i = 0;
	while(i < n){
		if(cow1[i] == cow2[i]){
			++i;
			continue;
		}
		++cnt;
		while(i < n && cow1[i] != cow2[i]){
			++i;
		}
	}
	printf("%d", cnt);
	return 0;
}
