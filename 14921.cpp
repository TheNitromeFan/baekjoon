#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> liquid(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &liquid[i]);
	}
	sort(liquid.begin(), liquid.end());
	int start = 0, end = n - 1;
	int ans = 2000000001;
	while(start < end){
		int sum = liquid[start] + liquid[end];
		if(abs(ans) > abs(sum)){
			ans = sum;
		}
		if(sum > 0){
			--end;
		}else{
			++start;
		}
	}
	printf("%d", ans);
	return 0;
}
