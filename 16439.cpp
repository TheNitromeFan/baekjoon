#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> a;
	a.resize(n);
	for(int i = 0; i < n; ++i){
		a[i].resize(m);
		for(int j = 0; j < m; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	string bitmask(3, 1);
	bitmask.resize(m, 0);
	int ans = 0;
	do{
		int cmp = 0;
		for(int i = 0; i < n; ++i){
			vector<int> tmp;
			for(int j = 0; j < m; ++j){
				if(bitmask[j]){
					tmp.push_back(a[i][j]);
				}
			}
			cmp += *max_element(tmp.begin(), tmp.end());
		}
		if(ans < cmp){
			ans = cmp;
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	printf("%d", ans);
	return 0;
}
