#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> v;
	v.resize(n);
	for(int i = 0; i < n; ++i){
		v[i].resize(m);
		for(int j = 0; j < m; ++j){
			scanf("%d", &v[i][j]);
		}
	}
	sort(v.begin(), v.end());
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(v[i-1][j] > v[i][j]){
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
	return 0;
}
