#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	char park[2][101];
	scanf("%s", park[0]);
	scanf("%s", park[1]);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(park[0][i] == 'C' && park[1][i] == 'C'){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
