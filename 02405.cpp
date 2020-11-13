#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> a(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	int ans = 0, tmp;
	for(int i = 1; i < n - 1; ++i){
		tmp = abs(2 * a[i] - a[i + 1] - a[0]);
		if(tmp > ans){
			ans = tmp;
		}
		tmp = abs(2 * a[i] - a[i - 1] - a[n - 1]);
		if(tmp > ans){
			ans = tmp;
		}
	}
	printf("%d", ans);
	return 0;
}
