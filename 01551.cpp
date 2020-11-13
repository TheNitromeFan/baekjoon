#include <cstdio>
#include <vector>

using namespace std;

vector<int> diff(vector<int> &a){
	vector<int> ret(a.size() - 1, 0);
	for(unsigned i = 0; i < ret.size(); ++i){
		ret[i] = a[i + 1] - a[i];
	}
	return ret;
}

int main(){
	unsigned n, k;
	scanf("%u %u", &n, &k);
	vector<int> a(n, 0);
	for(unsigned i = 0; i < n - 1; ++i){
		scanf("%d,", &a[i]);
	}
	scanf("%d", &a[n - 1]);
	for(unsigned j = 0; j < k; ++j){
		a = diff(a);
	}
	for(unsigned i = 0; i < a.size() - 1; ++i){
		printf("%d,", a[i]);
	}
	printf("%d", a[a.size() - 1]);
	return 0;
}
