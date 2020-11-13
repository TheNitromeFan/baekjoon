#include <cstdio>
#include <vector>

int main(){
	int n;
	scanf("%d", &n);
	std::vector<int> scores(n, 0);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &scores[i]);
	}
	for(int i = n - 1; i > 0; --i){
		if(scores[i - 1] >= scores[i]){
			ans += scores[i - 1] - scores[i] + 1;
			scores[i - 1] = scores[i] - 1;
		}
	}
	printf("%d", ans);
	return 0;
}
