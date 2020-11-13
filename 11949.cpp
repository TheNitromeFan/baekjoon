#include <cstdio>
#include <algorithm>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[100];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	for(int j = 1; j <= m; ++j){
		for(int i = 0; i + 1 < n; ++i){
			if(a[i] % j > a[i + 1] % j){
				std::swap(a[i], a[i + 1]);
			}
		}
	}
	for(int i = 0; i < n; ++i){
		printf("%d\n", a[i]);
	}
	return 0;
}
