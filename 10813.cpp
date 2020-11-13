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
		int i, j;
		scanf("%d %d", &i, &j);
		swap(baskets[i - 1], baskets[j - 1]);
	}
	for(int idx = 0; idx < n; ++idx){
		printf("%d ", baskets[idx]);
	}
	return 0;
}
