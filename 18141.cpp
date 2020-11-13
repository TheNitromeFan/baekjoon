#include <cstdio>
#include <cstdlib>

int alwaysInteger(int a[50], int n){
	for(int k = 0; k < n; ++k){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(i == j || j == k || k == i){
					continue;
				}
				if(abs(a[i] - a[j]) % abs(a[k]) != 0){
					return false;
				}
			}
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[50];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	printf("%s", alwaysInteger(a, n) ? "yes" : "no");
	return 0;
}
