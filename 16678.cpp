#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> a(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end(), greater<int>());
	long long ans = 0;
	int t = 1;
	for(int i = 1; i <= n; ++i){
		if(a.back() >= t){
			ans += a.back() - t;
			++t;
		}
		a.pop_back();
	}
	printf("%lld", ans);
	return 0;
}
