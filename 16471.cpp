#include <cstdio>
#include <algorithm>

using std::sort;

int main(){
	int n;
	scanf("%d", &n);
	int player[100000], owner[100000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &player[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", &owner[i]);
	}
	sort(player, player + n);
	sort(owner, owner + n);
	int cnt = 0;
	int i2 = 0;
	for(int i1 = 0; i1 < n; ++i1){
		while(i2 < n && owner[i2] <= player[i1]){
			++i2;
		}
		if(i2 < n){
			// printf("%d %d\n", i1, i2);
			++cnt;
			++i2;
		}
	}
	// printf("%d\n", cnt);
	printf("%s", cnt >= (n + 1) / 2 ? "YES" : "NO");
	return 0;
}
