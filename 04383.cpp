#include <cstdio>
#include <cstdlib>
#define MAX 3000

bool jolly(bool j[MAX], int n){
	for(int i = 1; i < n; ++i){
		if(!j[i]){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		int a[MAX];
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		bool jump[MAX] = {};
		for(int i = 0; i < n - 1; ++i){
			jump[abs(a[i + 1] - a[i])] = true;
		}
		printf("%s\n", jolly(jump, n) ? "Jolly" : "Not jolly");
	}
	return 0;
}
