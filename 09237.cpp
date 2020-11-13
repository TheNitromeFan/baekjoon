#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end(), greater<int>());
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(ans < i + v[i] + 2){
			ans = i + v[i] + 2;
		}
	}
	printf("%d", ans);
	return 0;
}
