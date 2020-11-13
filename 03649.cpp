#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void find_indices(vector<int> &v, int sum){
	int i = 0, j = v.size() - 1;
	while(i < j){
		int k = v[i] + v[j];
		if(k == sum){
			printf("yes %d %d\n", v[i], v[j]);
			return;
		}else if(k < sum){
			++i;
		}else{
			--j;
		}
	}
	printf("danger\n");
}

int main(){
	int x;
	while(scanf("%d", &x) == 1){
		x *= 10000000;
		int n;
		scanf("%d", &n);
		vector<int> v(n, 0);
		for(int i = 0; i < n; ++i){
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		find_indices(v, x);
	}
	return 0;
}
