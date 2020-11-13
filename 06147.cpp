#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n, b;
	scanf("%d %d", &n, &b);
	vector<int> h(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &h[i]);
	}
	sort(h.begin(), h.end(), greater<int>());
	int ans, sum = 0;
	for(ans = 0; sum < b; ++ans){
		sum += h[ans];
	}
	printf("%d", ans);
	return 0;
}
