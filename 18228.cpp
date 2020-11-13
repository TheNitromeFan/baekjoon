#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	unsigned n;
	scanf("%u", &n);
	vector<int> v(n, 0);
	unsigned idx = 0;
	for(unsigned i = 0; i < n; ++i){
		scanf("%d", &v[i]);
		if(v[i] == -1){
			idx = i;
		}
	}
	printf("%d", *min_element(v.begin(), v.begin() + idx) + *min_element(v.begin() + idx + 1, v.end()));
	return 0;
}
