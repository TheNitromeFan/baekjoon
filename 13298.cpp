#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int a0 = 0; a0 < n; ++a0){
		int l1, a1, l2, a2, lt, at;
		scanf("%d %d %d %d %d %d", &l1, &a1, &l2, &a2, &lt, &at);
		if(l1 * a2 - l2 * a1 == 0){
			if(lt * a2 - l2 * at == 0){
				int x = 0, y = 0;
				int cnt = 0;
				for(int x1 = 1; l1 * x1 < lt; ++x1){
					if((lt - l1 * x1) % l2 == 0 && (lt - l1 * x1) / l2 > 0){
						x = x1;
						y = (lt - l1 * x1) / l2;
						++cnt;
					}
				}
				if(cnt == 1){
					printf("%d %d\n", x, y);
				}else{
					printf("?\n");
				}
			}else{
				printf("?\n");
			}
		}else{
			if((lt * a2 - l2 * at) % (l1 * a2 - l2 * a1) == 0
			&& (lt * a2 - l2 * at) / (l1 * a2 - l2 * a1) > 0
			&& (l1 * at - lt * a1) / (l1 * a2 - l2 * a1) > 0){
				printf("%d %d\n", (lt * a2 - l2 * at) / (l1 * a2 - l2 * a1), (l1 * at - lt * a1) / (l1 * a2 - l2 * a1));
			}else{
				printf("?\n");
			}
		}
	}
	return 0;
}
