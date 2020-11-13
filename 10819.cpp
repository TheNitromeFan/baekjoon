#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int sum_of_diffs(vector<int> &a){
	int ret = 0;
	for(int i = 0; i < a.size() - 1; ++i){
		ret += abs(a[i] - a[i + 1]);
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> a(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	int ans = 0;
	do{
		int cmp = sum_of_diffs(a);
		if(cmp > ans){
			ans = cmp;
		}
	}while(next_permutation(a.begin(), a.end()));
	printf("%d", ans);
	return 0;
}
