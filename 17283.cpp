#include <cstdio>

int main(){
	int len, ratio;
	scanf("%d %d", &len, &ratio);
	int ans = 0;
	int n = 0;
	while(true){
		++n;
		int branch = int(len * ratio / 100);
		if(branch <= 5){
			break;
		}
		ans += branch * (1 << n);
		len = branch;
	}
	printf("%d", ans);
	return 0;
}
