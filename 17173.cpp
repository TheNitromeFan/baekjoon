#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	bool arr[1001] = {};
	for(int i = 0; i < m; ++i){
		int x;
		scanf("%d", &x);
		for(int mult = 1; mult * x <= n; ++mult){
			arr[mult * x] = true;
		}
	}
	int sum = 0;
	for(int j = 1; j <= n; ++j){
		if(arr[j]){
			sum += j;
		}
	}
	printf("%d", sum);
	return 0;
}
