#include <cstdio>

bool rem[1000000];

int main(){
	int n;
	scanf("%d", &n);
	for(int a0 = 0; a0 < n; ++a0){
		int g;
		scanf("%d", &g);
		int sin[301];
		for(int i = 0; i < g; ++i){
			scanf("%d", &sin[i]);
		}
		for(int mod = g; ; ++mod){
			bool flag = false;
			for(int i = 0; i < g; ++i){
				if(rem[sin[i] % mod]){
					flag = true;
					break;
				}
				rem[sin[i] % mod] = true;
			}
			if(!flag){
				printf("%d\n", mod);
			}
			for(int i = 0; i < g; ++i){
				rem[sin[i] % mod] = false;
			}
			if(!flag){
				break;
			}
		}
	}
	return 0;
}
