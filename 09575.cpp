#include <cstdio>

bool only5or8(int n){
	while(n > 0){
		if(n % 10 != 5 && n % 10 != 8){
			return false;
		}
		n /= 10;
	}
	return true;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int a[50], b[50], c[50];
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		int l;
		scanf("%d", &l);
		for(int j = 0; j < l; ++j){
			scanf("%d", &b[j]);
		}
		int m;
		scanf("%d", &m);
		for(int k = 0; k < m; ++k){
			scanf("%d", &c[k]);
		}
		bool found[100000] = {};
		int ans = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < l; ++j){
				for(int k = 0; k < m; ++k){
					if(only5or8(a[i] + b[j] + c[k]) && !found[a[i] + b[j] + c[k]]){
						++ans;
						found[a[i] + b[j] + c[k]] = true;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
