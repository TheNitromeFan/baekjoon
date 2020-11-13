#include <cstdio>
#include <cstdlib>
#include <algorithm>

int main(){
	int n;
	scanf("%d", &n);
	int x;
	scanf("%d", &x);
	int sum = 0;
	for(int i = 0; i < n; ++i){
		int p1, p2;
		scanf("%d %d", &p1, &p2);
		if(abs(p1 - p2) <= x){
			sum += std::max(p1, p2);
		}else{
			int p3;
			scanf("%d", &p3);
			sum += p3;
		}
	}
	printf("%d", sum);
	return 0;
}
