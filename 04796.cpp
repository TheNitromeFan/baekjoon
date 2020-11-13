#include <cstdio>
#include <algorithm>

int main(){
	int cnt = 0;
	while(true){
		++cnt;
		int len, p, v;
		scanf("%d %d %d", &len, &p, &v);
		if(len == 0 && p == 0 && v == 0){
			break;
		}
		int ans = v / p * len + std::min(len, v % p);
		printf("Case %d: %d\n", cnt, ans);
	}
	return 0;
}
