#include <cstdio>

void print_sequence(int cnt[10001], int m, int ans[10], int pos){
	if(pos == m){
		for(int i = 0; i < m; ++i){
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	for(int x = (pos == 0 ? 1 : ans[pos - 1]); x <= 10000; ++x){
		if(cnt[x] >= 1){
			--cnt[x];
			ans[pos] = x;
			print_sequence(cnt, m, ans, pos + 1);
			++cnt[x];
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int cnt[10001] = {};
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	int ans[10] = {};
	print_sequence(cnt, m, ans, 0);
	return 0;
}
