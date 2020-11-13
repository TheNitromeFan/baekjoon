#include <cstdio>

int main(){
	int students[2][7] = {};
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i){
		int s, y;
		scanf("%d %d", &s, &y);
		++students[s][y];
	}
	int ans = 0;
	for(int s = 0; s <= 1; ++s){
		for(int y = 1; y <= 6; ++y){
			ans += (students[s][y] % k == 0) ? students[s][y] / k : students[s][y] / k + 1;
		}
	}
	printf("%d", ans);
	return 0;
}
