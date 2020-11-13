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
	int a = 0, b = n - 1;
	while(start < end){
		int sum = liquid[start] + liquid[end];
		if(ans > abs(sum)){
			ans = abs(sum);
			a = start;
			b = end;
		}
		if(sum > 0){
			--end;
		}else{
			++start;
		}
	}
	printf("%d %d", liquid[a], liquid[b]);
	return 0;
}
