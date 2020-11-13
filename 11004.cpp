#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	static int a[5000001];
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a+1, a+1+n);
	printf("%d", a[k]);
	return 0;
}
