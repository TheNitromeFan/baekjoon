#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> baskets(n, 0);
	for(int idx = 0; idx < n; ++idx){
		baskets[idx] = idx + 1;
	}
	for(int a0 = 0; a0 < m; ++a0){
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);
		rotate(baskets.begin() + i - 1, baskets.begin() + k - 1, baskets.begin() + j);
	}
	for(int idx = 0; idx < n; ++idx){
		printf("%d ", baskets[idx]);
	}
	return 0;
}
