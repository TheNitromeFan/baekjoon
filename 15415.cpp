#include <cstdio>

int main(){
	long long w;
	scanf("%lld", &w);
	int n;
	scanf("%d", &n);
	long long area = 0;
	for(int i = 0; i < n; ++i){
		int wi, li;
		scanf("%d %d", &wi, &li);
		area += wi * li;
	}
	printf("%lld", area / w);
	return 0;
}
