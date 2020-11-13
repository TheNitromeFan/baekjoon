#include <cstdio>
#define MAX (1000 + 1)

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	int max = 0, ans = 0;
	for(int i = 1; i <= n; ++i){
		int cur = i;
		bool visited[MAX] = {};
		int cnt = 0;
		while(!visited[cur]){
			visited[cur] = true;
			++cnt;
			cur = a[cur];
		}
		if(cnt > max){
			max = cnt;
			ans = i;
		}
	}
	printf("%d", ans);
	return 0;
}
