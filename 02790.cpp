#include <cstdio>
#include <algorithm>
#include <functional>

int main(){
	int n;
	scanf("%d", &n);
	static int a[300000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a+n, std::greater<int>());
	int cnt = 0, thres = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] + n >= thres){
			++cnt;
		}
		if(a[i] + i + 1 > thres){
			thres = a[i] + i + 1;
		}
	}
	printf("%d", cnt);
	return 0;
}
