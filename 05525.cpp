#include <cstdio>
#define MAX (1000000 + 1)

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char ioi[MAX];
	scanf("%s", ioi);
	int ans = 0;
	int combo = 0;
	int idx = 0;
	while(idx + 2 < m){
		if(ioi[idx] == 'I' && ioi[idx + 1] == 'O' && ioi[idx + 2] == 'I'){
			++combo;
			idx += 2;
		}else{
			if(combo >= n){
				ans += combo - n + 1;
			}
			combo = 0;
			++idx;
		}
	}
	if(combo >= n){
		ans += combo - n + 1;
	}
	printf("%d", ans);
	return 0;
}
