#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int m;
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i){
		vector<int> v(3, 0);
		for(int j = 0; j < 3; ++j){
			scanf("%d", &v[j]);
		}
		sort(v.begin(), v.end());
		printf("Case #%d: %s\n", i, v[0] * v[0] + v[1] * v[1] == v[2] * v[2] ? "YES" : "NO");
	}
	return 0;
}
