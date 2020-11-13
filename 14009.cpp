#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a[200001];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	long long ans = 0;
	for(int i = 1; i <= n;){
		int lastJ = i + 1;
		for(int j = i + 1; j <= n; ++j){
			if(a[j] == a[j - 1]){
				break;
			}
			if(j >= i + 2){
				bool inc1 = a[j - 2] < a[j - 1], inc2 = a[j - 1] < a[j];
				if(inc1 == inc2){
					break;
				}
			}
			++lastJ;
		}
		ans += (long long)(lastJ - i) * (lastJ - i + 1) / 2;
		if(lastJ > n){
			break;
		}
		if(a[lastJ] == a[lastJ - 1]){
			i = lastJ;
		}else if(lastJ == i + 1){
			i = lastJ;
		}else{
			i = lastJ - 1;
			--ans;
		}
	}
	printf("%lld", ans);
	return 0;
}
