#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int students, apples;
		scanf("%d %d", &students, &apples);
		ans += apples % students;
	}
	printf("%d", ans);
	return 0;
}
