#include <cstdio>
#include <vector>

using namespace std;

vector<int> max_len(int n){
	vector<int> ret;
	for(int i = 0; i <= n; ++i){
		vector<int> cmp = {n, i};
		while(cmp[cmp.size() - 2] - cmp[cmp.size() - 1] >= 0){
			cmp.push_back(cmp[cmp.size() - 2] - cmp[cmp.size() - 1]);
		}
		if(cmp.size() > ret.size()){
			ret = cmp;
		}
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> ans = max_len(n);
	printf("%llu\n", ans.size());
	for(int x : ans){
		printf("%d ", x);
	}
	return 0;
}
