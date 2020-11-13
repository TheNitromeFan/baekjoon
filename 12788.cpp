#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int borrow(int a[1000], int n, int target){
	int idx = 0;
	while(idx < n && target > 0){
		target -= a[idx];
		++idx;
	}
	if(idx == n && target > 0){
		return -1;
	}else{
		return idx;
	}
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int a[1000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a + n, greater<int>());
	int ans = borrow(a, n, m * k);
	if(ans == -1){
		printf("STRESS");
	}else{
		printf("%d", ans);
	}
	return 0;
}
