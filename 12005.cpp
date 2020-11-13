#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	unsigned n, k;
	scanf("%u %u", &n, &k);
	vector<int> v(n);
	for(unsigned i = 0; i < n; ++i){
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	unsigned i1 = 0, i2 = 0;
	int low = 1, high = k + 1;
	while(i2 < n && v[i2] <= high){
		++i2;
	}
	unsigned maxLen = i2 - i1;
	while(i2 < n){
		++high;
		while(i2 < n && v[i2] <= high){
			++i2;
		}
		++low;
		while(v[i1] < low){
			++i1;
		}
		if(maxLen < i2 - i1){
			maxLen = i2 - i1;
		}
	}
	printf("%u", maxLen);
	return 0;
}
