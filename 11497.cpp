#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		vector<int> v(n, 0);
		for(int j = 0; j < n; ++j){
			scanf("%d", &v[j]);
		}
		sort(v.begin(), v.end());
		int ans = v[2] - v[0];
		for(int i = 1; i + 2 < n; ++i){
			if(ans < v[i + 2] - v[i]){
				ans = v[i + 2] - v[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
