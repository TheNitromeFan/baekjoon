#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &v[i]);
	}
	int ans = 0;
	vector<int> bitmask(3, 1);
	bitmask.resize(n - 1, 0);
	do{
		int sum = 0, prod = v[0];
		for(int i = 1; i < n; ++i){
			if(bitmask[i - 1]){
				sum += prod;
				prod = 1;
			}
			prod *= v[i];
		}
		sum += prod;
		if(ans < sum){
			ans = sum;
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	printf("%d", ans);
	return 0;
}
